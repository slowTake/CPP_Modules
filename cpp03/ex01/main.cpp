#include "ClapTrap.hpp"

int main(void)
{
    // 1. Create the bots
    ClapTrap hero("Timmy");
    ClapTrap hostile("Eppy");

    std::cout << "\n--- ROUND 1: Basic Combat ---" << std::endl;
    hero.attack("Eppy");
    hostile.takeDamage(5); // Now Eppy has 5 HP

    std::cout << "\n--- ROUND 2: Repairing ---" << std::endl;
    hostile.beRepaired(3); // Now Eppy has 8 HP

    std::cout << "\n--- ROUND 3: Energy Exhaustion ---" << std::endl;
    // Eppy repairs himself 9 more times (Eppy started with 10 energy, used 1 for repair, 9 left)
    for (int i = 0; i < 10; i++) {
        hostile.beRepaired(1);
    }
    // Eppy should now fail to attack because energy is 0
    hostile.attack("Timmy");

    std::cout << "\n--- ROUND 4: Lethal Damage ---" << std::endl;
    hero.takeDamage(20); // Should set HP to 0, not underflow
    hero.beRepaired(10); // Should fail because hero is dead

    std::cout << "\n--- ROUND 5: Cleanup ---" << std::endl;
    // Destructors will be called automatically here
    return 0;
}