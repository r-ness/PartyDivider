#pragma once

enum Role
{
    Buffer,
    Healer,
    BDancer,
    SSinger,
    Knight,
    Damager,
    Count
};

struct Player
{
    Role role;
    int power;
};
