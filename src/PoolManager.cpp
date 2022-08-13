#include "PoolManager.h"

#include <algorithm>

PoolManager& PoolManager::inst()
{
    static PoolManager manager;
    return manager;
}

bool PoolManager::isEmpty() const
{
    return std::all_of(playersByRole_.begin(), playersByRole_.end(), [](const auto& roleAndPlayers) {
        return roleAndPlayers.second.empty();
    });
}

static void sortPlayers(std::deque<Player>& players)
{
    std::sort(players.begin(), players.end(), [](const Player& left, const Player& right) {
        return left.power > right.power;
    });
}

void PoolManager::add(const Player& player)
{
    auto& players{ playersByRole_[player.role] };
    players.push_back(player);
    sortPlayers(players);
}

void PoolManager::add(const std::vector<Player>& players)
{
    for (auto& palyer : players)
        playersByRole_[palyer.role].push_back(palyer);

    for (auto& [_, players] : playersByRole_)
        sortPlayers(players);
}

std::optional<Player> PoolManager::takeTopPlayer()
{
    using PoolPlayerIt = std::pair<Role, std::deque<Player>::const_iterator>;

    std::optional<PoolPlayerIt> topPlayer{};

    for (const auto& [role, players] : playersByRole_)
    {
        for (auto it{ players.begin() }; it != players.end(); ++it)
        {
            if (!topPlayer.has_value() && it != players.end()) // First init
            {
                topPlayer = { role, it };
                continue;
            }

            if (it->power < topPlayer->second->power)
                continue;

            topPlayer = { role, it };
        }
    }

    if (!topPlayer.has_value())
        return std::nullopt;

    const auto player{ *(topPlayer->second) };

    playersByRole_[topPlayer->first].erase(topPlayer->second);
    return player;
}

std::optional<Player> PoolManager::takeTopPlayer(Role role)
{
    const auto poolsIt{ playersByRole_.find(role) };
    if (poolsIt == playersByRole_.end())
        return std::nullopt;

    if (poolsIt->second.empty())
        return std::nullopt;

    auto result{ poolsIt->second.front() };
    poolsIt->second.pop_front();
    return result;
}

