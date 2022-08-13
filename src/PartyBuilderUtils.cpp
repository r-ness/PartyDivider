#include "PartyBuilderUtils.h"
#include "PartyBuilderStructs.h"
#include "PoolManager.h"

#include <array>

static bool setupPlayerFromPoolByPriority(const Party& party, Party::Slot& forSlot)
{
    /**
    * There should be an algorithm for calculating the desired player role
    */

    const std::array<Role, Role::Count> kPriorityMap
    {
        Role::Knight,
        Role::Healer,
        Role::Damager,
        Role::Buffer,
        Role::SSinger,
        Role::BDancer,
    };

    for (const auto role : kPriorityMap)
    {
        const auto playerOpt{ PoolManager::inst().takeTopPlayer(role) };
        if (!playerOpt.has_value())
            continue;

        forSlot.player = playerOpt.value();
        forSlot.fit.state = party_builder::FitState::PickedByPriority;
        return true;
    }

    return false;
}

bool party_builder::setupPlayerFromPool(Party& party)
{
    // Pick by preset
    for (auto& slot : party.slots())
    {
        if (slot.fit.state != FitState::Waiting)
            continue;

        const auto playerOpt{ PoolManager::inst().takeTopPlayer(slot.fit.role) };
        if (!playerOpt.has_value())
        {
            slot.fit.state = FitState::RoleNotFoundByPreset;
            continue;
        }

        slot.player = playerOpt.value();
        slot.fit.state = FitState::PickedByPreset;
        return true;
    }

    // Pick by priority
    for (auto& slot : party.slots())
    {
        if (slot.fit.state != FitState::RoleNotFoundByPreset)
            continue;

        if (!setupPlayerFromPoolByPriority(party, slot))
            continue;

        return true;
    }

    // Pick what is (error case - preset and priority do not handle all role cases)
    for (auto& slot : party.slots())
    {
        if (slot.fit.state != FitState::RoleNotFoundByPreset)
            continue;

        const auto playerOpt{ PoolManager::inst().takeTopPlayer() };
        if (!playerOpt.has_value())
            continue;

        slot.player = playerOpt.value();
        slot.fit.state = FitState::PickedByWhatIs;
        return true;
    }

    // PlayersPool is empty
    return false;
}
