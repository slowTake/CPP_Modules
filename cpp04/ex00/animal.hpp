#pragma once

#include <string>
#include <iostream>

class animal
{
	protected:
	 std::string type;

	public:
	 animal();
	 animal(const animal &copy);
	 animal &operator=(const animal &copy);
	 ~animal();
};

class Dog : animal
{
	private:
	 
	public:
	 Dog();
	 Dog(const Dog &copy);
	 Dog &operator=(const Dog &copy);
	 ~Dog();

	 void makeSound();
};

class Cat :animal
{
	private:

	public:
	 Cat();
	 Cat(const Cat &copy);
	 Cat &operator=(const Cat &copy);
	 ~Cat();
	 
	 void makeSound();
};