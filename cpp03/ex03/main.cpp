#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. INITIALIZING DIAMOND ---" << std::endl;
    // This should trigger: ClapTrap, FragTrap, ScavTrap, then DiamondTrap constructors
    DiamondTrap monster("Monster");

    std::cout << "\n--- 2. IDENTITY CHECK ---" << std::endl;
    // Expected: I am Monster and my ClapTrap parent is Monster_clap_name
    monster.whoAmI();

    std::cout << "\n--- 3. STATS & ATTACK CHECK ---" << std::endl;
    // Should use ScavTrap's attack: "ScavTrap Monster attacks..."
    // Damage should be 30 (from FragTrap)
    monster.attack("the training dummy");

    std::cout << "\n--- 4. SPECIAL ABILITIES ---" << std::endl;
    monster.guardGate();   // From ScavTrap
    monster.highFivesGuys(); // From FragTrap

    std::cout << "\n--- 5. DESTRUCTION ORDER ---" << std::endl;
    // When main ends, they should destruct in reverse order
    return 0;
}