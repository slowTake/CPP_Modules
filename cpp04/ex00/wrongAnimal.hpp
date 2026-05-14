#pragma once

#include <string>
#include <iostream>

class wrongAnimal
{
    protected:
        std::string type;

    public:
        wrongAnimal();
        wrongAnimal(const wrongAnimal &copy);
        wrongAnimal &operator=(const wrongAnimal &copy);
        ~wrongAnimal();

        void makeSound() const;
        std::string getType() const;
};

class WrongCat : public wrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &copy);
        WrongCat &operator=(const WrongCat &copy);
        ~WrongCat();

        void makeSound() const;
};
