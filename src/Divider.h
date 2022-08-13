#pragma once

#include "Team.h"

#include <vector>

class Divider
{
public:
    void setNumberOfTeams(size_t numberOfTeams);
    bool divide();
    std::vector<Team> getTeams();

private:
    std::vector<Team>::iterator getWeakestTeam();

    size_t numberOfTeams_{ 2 };
    std::vector<Team> teams_;
};
