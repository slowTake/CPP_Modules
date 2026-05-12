#include "ScavTrap.hpp"

int main() {
    std::cout << "--- CREATING CLAPTRAP ---" << std::endl;
    ClapTrap clap("Basic-Bot");

    std::cout << "\n--- CREATING SCAVTRAP ---" << std::endl;
    // Notice how this will call ClapTrap constructor THEN ScavTrap constructor
    ScavTrap scav("Gate-Guardian");

    std::cout << "\n--- TESTING STATS & ATTACK ---" << std::endl;
    clap.attack("a fly");
    scav.attack("a bandit"); // Should show 20 damage, not 0

    std::cout << "\n--- TESTING INHERITED FUNCTIONS ---" << std::endl;
    // ScavTrap didn't define takeDamage, but it inherited it!
    scav.takeDamage(30);
    scav.beRepaired(10);

    std::cout << "\n--- TESTING SPECIAL CAPACITY ---" << std::endl;
    scav.guardGate();

    std::cout << "\n--- TESTING ENERGY EXHAUSTION ---" << std::endl;
    // ScavTrap has 50 energy, let's see it work
    for (int i = 0; i < 50; i++) {
        scav.attack("the wall");
    }
    scav.attack("one last time"); // Should fail

    std::cout << "\n--- DESTRUCTORS ---" << std::endl;
    // Watch the order: Scav destructor first, then Clap destructor
    return 0;
}
