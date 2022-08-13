#pragma once

#include "Team.h"

#include <vector>

namespace printer
{
    enum PlayerSort
    {
        None,
        ByRole,
        ByPower,
    };

    void showAllTeams(const std::vector<Team>& teams, PlayerSort sort);
    void showPoolPlayers(const std::vector<Player>& players);
}
