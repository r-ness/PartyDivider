#include "TeamsPrinter.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <string>

namespace cast
{
    const std::array< std::string, Role::Count > kRoleString{
        "Buffer ",
        "Healer ",
        "BDancer",
        "SSinger",
        "Knight ",
        "Damager",
    };
}

static void printParty(const std::vector<Player>& players, printer::PlayerSort sort)
{
    std::vector<Player> sortedByRole{ players };

    switch (sort)
    {
    case printer::ByRole:
        std::sort(sortedByRole.begin(), sortedByRole.end(), [](const Player& left, const Player& right) { return left.role < right.role; });
        break;
    case printer::ByPower:
        std::sort(sortedByRole.begin(), sortedByRole.end(), [](const Player& left, const Player& right) { return left.power > right.power; });
        break;
    case printer::None:
    default:
        break;
    }

    for (size_t i{}; i < sortedByRole.size(); ++i)
    {
        std::cout << "[Player " << i + 1 << "]: \t"
            << cast::kRoleString[sortedByRole[i].role] << "\t"
            << sortedByRole[i].power << std::endl;
    }
}

void printer::showAllTeams(const std::vector<Team>& teams, PlayerSort sort)
{
    for (size_t i{}; i < teams.size(); ++i)
    {
        std::cout << "[Team " << i + 1 << "] power:\t" << teams[i].getPower() << std::endl;
        std::cout << std::endl;

        const auto& parties{ teams[i].parties };
        for (size_t j{}; j < parties.size(); ++j)
        {
            std::cout << "Party " << j + 1 << "" << std::endl;
            printParty(parties[j].getPlayers(), sort);
            std::cout << std::endl;
        }

        std::cout << std::endl << std::endl;
    }
}

void printer::showPoolPlayers(const std::vector<Player>& players)
{
    std::vector<Player> sortedByRole{ players };
    std::sort(sortedByRole.begin(), sortedByRole.end(), [](const Player& left, const Player& right) { return left.role < right.role; });

    for (auto& player : sortedByRole)
        std::cout << cast::kRoleString[player.role] << "\t" << player.power << std::endl;

    std::cout << std::endl << std::endl;
}
