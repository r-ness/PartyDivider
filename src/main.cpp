#include "PoolManager.h"
#include "PlayerPool.h"
#include "Divider.h"
#include "TeamsPrinter.h"
#include "RandomPlayerPool.h"

int main()
{
    const auto randPool{ getRandomPlayerPool() };
    printer::showPoolPlayers(randPool);

    //PoolManager::inst().add(kPlayerPool1);
    PoolManager::inst().add(randPool);

    constexpr auto kNumberOfTeams{ 2 }; // Red, Blue

    Divider divider;
    divider.setNumberOfTeams(kNumberOfTeams);

    const auto status{ divider.divide() };
    if (!status)
        return 1;

    const auto result{ divider.getTeams() };
    printer::showAllTeams(result, printer::PlayerSort::ByRole);

    return 0;
}
