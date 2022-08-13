#pragma once

#include "Player.h"
#include "PartyBuilderStructs.h"

#include <array>
#include <vector>

namespace party_builder
{
    constexpr std::array<Role, 9> kFitP1B2H2D3K1
    {
        Role::Buffer,
        Role::Damager,
        Role::Healer,
        Role::BDancer,
        Role::Damager,
        Role::SSinger,
        Role::Healer,
        Role::Knight,
        Role::Damager,
    };

    constexpr std::array<Role, 9> kFitP1B2H1D4K1
    {
        Role::Buffer,
        Role::Damager,
        Role::Healer,
        Role::BDancer,
        Role::Damager,
        Role::SSinger,
        Role::Knight,
        Role::Damager,
        Role::Damager,
    };

    constexpr std::array<Role, 9> kFitP1B2H2D4
    {
        Role::Buffer,
        Role::Damager,
        Role::Healer,
        Role::BDancer,
        Role::Damager,
        Role::SSinger,
        Role::Healer,
        Role::Damager,
        Role::Damager,
    };

    constexpr std::array<std::array<Role, 9>, party_builder::Preset::Count> kPresetMap
    {
        kFitP1B2H2D3K1,
        kFitP1B2H1D4K1,
        kFitP1B2H2D4,
    };

    std::vector<Role> getPresetMap(party_builder::Preset preset)
    {
        const auto& fitmap{ kPresetMap[preset] };
        return std::vector<Role>{fitmap.begin(), fitmap.end()};
    }
}
