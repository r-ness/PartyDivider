#pragma once

#include "Player.h"
#include "PartyBuilderStructs.h"

#include <vector>
#include <optional>

class Party
{
public:
    struct Slot
    {
        party_builder::FitSlot fit;
        std::optional< Player >player;
    };

    Party(const std::vector<Role>& partyPreset);
    bool isFull() const;
    int getPower() const;
    std::vector<Player> getPlayers() const;
    std::vector<Slot>& slots() { return slots_; }

private:
    std::vector<Slot> slots_;
};
