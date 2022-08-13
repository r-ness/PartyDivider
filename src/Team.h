#pragma once

#include "Party.h"

#include <vector>
#include <numeric>

struct Team
{
    std::vector<Party> parties;

    int getPower() const
    {
        return std::accumulate(parties.begin(), parties.end(), 0, [](int sum, const Party& party) {
            return sum + party.getPower();
        });
    }
};
