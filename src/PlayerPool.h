#pragma once

#include "Player.h"

#include <vector>

const std::vector<Player> kPlayerPool1
{
    // Buffer
    { Role::Buffer, 195},
    { Role::Buffer, 163},

    // Healer
    { Role::Healer, 80},
    { Role::Healer, 164},
    { Role::Healer, 243},

    // Bd
    { Role::BDancer, 240},

    // Sws
    { Role::SSinger, 180},
    { Role::SSinger, 100},

    // Knight
    { Role::Knight, 153},
    { Role::Knight, 115},
    { Role::Knight, 111},

    // Damager
    { Role::Damager, 285},
    { Role::Damager, 204},
    { Role::Damager, 80},
    { Role::Damager, 243},
    { Role::Damager, 161},
    { Role::Damager, 189},
    { Role::Damager, 118},
};
