#include "Party.h"

#include <algorithm>
#include <iterator>
#include <numeric>

Party::Party(const std::vector<Role>& partyPreset)
{
    std::transform(partyPreset.begin(), partyPreset.end(), std::back_inserter(slots_), [](const Role role) {
        return Slot{
            party_builder::FitSlot{ role, party_builder::FitState::Waiting },
            std::nullopt,
        };
    });
}

bool Party::isFull() const
{
    return std::all_of(slots_.begin(), slots_.end(), [](const Slot& slot) { return slot.player.has_value(); });
}

int Party::getPower() const
{
    return std::accumulate(slots_.begin(), slots_.end(), 0, [](int sum, const Slot& slot) {
        return sum + (slot.player.has_value() ? slot.player->power : int{});
    });
}

std::vector<Player> Party::getPlayers() const
{
    std::vector<Player> result;
    for (const auto& slot : slots_)
    {
        if (!slot.player.has_value())
            continue;

        result.push_back(slot.player.value());
    }

    return result;
}
