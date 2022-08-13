#pragma once

#include "Player.h"

namespace party_builder
{
    enum Preset {
        P1B2H2D3K1,
        P1B2H1D4K1,
        P1B2H2D4,
        Count
    };

    enum FitState {
        Waiting,
        RoleNotFoundByPreset,
        PickedByPreset,
        PickedByPriority,
        PickedByWhatIs,
    };

    struct FitSlot
    {
        Role role;
        FitState state;
    };
}
