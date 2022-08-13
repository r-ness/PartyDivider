#pragma once

#include "Player.h"

#include <deque>
#include <map>
#include <optional>
#include <vector>

class PoolManager
{
public:
    static PoolManager& inst();
    void add(const Player& player);
    void add(const std::vector<Player>& players);
    bool isEmpty() const;

    std::optional<Player> takeTopPlayer();
    std::optional<Player> takeTopPlayer(Role role);

private:
    PoolManager() = default;
    std::map<Role, std::deque<Player>> playersByRole_;
};

