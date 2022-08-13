#include "RandomPlayerPool.h"

#include <array>
#include <ctime>
#include <cstdlib>

constexpr std::array<double, Role::Count> kRolePopularity
{
    0.2, // Buffer,
    0.3, // Healer,
    0.1, // BDancer,
    0.1, // SSinger,
    0.4, // Knight,
    0.9, // Damager,
};

std::vector<Player> getRandomPlayerPool()
{
    std::vector<Player> playerPool;

    std::srand(std::time(nullptr));

    for (size_t role{}; role < Role::Count; ++role)
    {
        const auto roleCount{ (std::rand() % 30) * kRolePopularity[role] };

        for (size_t player{}; player < roleCount; ++player)
        {
            const auto playerPower{ 50 + std::rand() % 250 };

            Player newPlayer{ static_cast<Role>(role), playerPower };
            playerPool.push_back(std::move(newPlayer));
        }
    }

    return playerPool;
}
