#include "Divider.h"
#include "PoolManager.h"
#include "PartyBuilderUtils.h"
#include "PartyPresetMap.h"

#include <algorithm>

void Divider::setNumberOfTeams(size_t numberOfTeams)
{
    numberOfTeams_ = numberOfTeams;
    teams_.resize(numberOfTeams_, Team{});
}

bool Divider::divide()
{
    if (teams_.empty())
        return false;

    while (!PoolManager::inst().isEmpty())
    {
        // Determine the team that now selects the player
        const auto teamIt{ getWeakestTeam() };

        // Create a new party if needed
        if (teamIt->parties.empty() || teamIt->parties.back().isFull())
        {
            const auto randomPreset{ party_builder::Preset::P1B2H2D3K1 }; // TODO: rand preset
            auto party{ party_builder::getPresetMap(randomPreset) };
            teamIt->parties.push_back(std::move(party));
        }

        /*
        * Find the right role for party
        * take player from pool
        * and set to party
        */
        party_builder::setupPlayerFromPool(teamIt->parties.back());
    }

    return true;
}

std::vector<Team> Divider::getTeams()
{
    return teams_;
}

std::vector<Team>::iterator Divider::getWeakestTeam()
{
    return std::min_element(teams_.begin(), teams_.end(), [](const Team& left, const Team& right) {
        return left.getPower() < right.getPower();
    });
}
