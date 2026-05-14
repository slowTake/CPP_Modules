#include "wrongAnimal.hpp"

/* --- wrongAnimal --- */

wrongAnimal::wrongAnimal() : type("wrongAnimal") {
    std::cout << "wrongAnimal constructor" << std::endl;
}

wrongAnimal::wrongAnimal(const wrongAnimal &copy) {
    *this = copy;
    std::cout << "wrongAnimal copy constructor" << std::endl;
}

wrongAnimal &wrongAnimal::operator=(const wrongAnimal &copy) {
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

wrongAnimal::~wrongAnimal() {
    std::cout << "wrongAnimal destructor" << std::endl;
}

void wrongAnimal::makeSound() const {
    std::cout << "wrongAnimal sound..." << std::endl;
}

std::string wrongAnimal::getType() const {
    return this->type;
}

/* --- WrongCat --- */

WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << "WrongCatto constructor" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCatto destructor" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCatto sound: Mooo? " << std::endl;
}