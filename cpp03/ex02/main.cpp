#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "===== CONSTRUCTORS =====" << std::endl;
    ClapTrap basic("CL4P-TP");
    ScavTrap guard("SC4V-TP");
    FragTrap heavy("FR4G-TP");

    std::cout << "\n===== ATTACK & DAMAGE TEST =====" << std::endl;
    // FragTrap should have 30 attack damage by default
    heavy.attack("a training dummy");
    
    // ClapTrap has 10 HP, so it would die instantly from a FragTrap attack
    basic.takeDamage(30); 

    std::cout << "\n===== FRAGTRAP SPECIAL CAPACITY =====" << std::endl;
    heavy.highFivesGuys();

    std::cout << "\n===== ENERGY CONSUMPTION TEST =====" << std::endl;
    // FragTrap has 100 energy! Let's burn some.
    std::cout << "FR4G-TP is doing some intense work..." << std::endl;
    for (int i = 0; i < 5; i++) {
        heavy.beRepaired(1);
    }
    
    std::cout << "\n===== COMPARING WITH SCAVTRAP =====" << std::endl;
    // ScavTrap has its own special move
    guard.guardGate();
    // ScavTrap has its own attack message (if you overrode it)
    guard.attack("the same dummy");

    std::cout << "\n===== DESTRUCTOR CHAIN =====" << std::endl;
    // Watch the terminal: FragTrap dies, then ClapTrap dies for it.
    // Then ScavTrap dies, then ClapTrap dies for it.
    return 0;
}