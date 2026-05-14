#include "animal.hpp"
#include "wrongAnimal.hpp"

int main()
{
    std::cout << "--- STANDARD ANIMAL TESTS ---" << std::endl;
    const animal* meta = new animal();
    const animal* j = new Dog();
    const animal* i = new Cat();

    std::cout << "Type of j: " << j->getType() << " " << std::endl;
    std::cout << "Type of i: " << i->getType() << " " << std::endl;

    i->makeSound(); // Will output the cat sound
    j->makeSound(); // Will output the dog sound
    meta->makeSound();

    std::cout << "\n--- CLEANING UP STANDARD ---" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- WRONG ANIMAL TESTS ---" << std::endl;
    const wrongAnimal* wrongMeta = new wrongAnimal();
    const wrongAnimal* wrongCat = new WrongCat();

    std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;

    // Because makeSound() is NOT virtual in WrongAnimal,
    // this will call WrongAnimal::makeSound() instead of WrongCat::makeSound()
    wrongCat->makeSound(); 
    wrongMeta->makeSound();

    std::cout << "\n--- CLEANING UP WRONG ---" << std::endl;
    delete wrongMeta;
    delete wrongCat; // Note: This only calls WrongAnimal destructor because it's not virtual!

    return 0;
}