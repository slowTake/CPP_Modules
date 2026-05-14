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
	 virtual ~animal();

	 virtual void makeSound() const;
	 std::string getType() const;
};

class Dog : public animal // Public otherwise defaults to private
{
	public:
	 Dog();
	 Dog(const Dog &copy);
	 Dog &operator=(const Dog &copy);
	 ~Dog() override;

	 void makeSound() const override;
};

class Cat : public animal
{
	public:
	 Cat();
	 Cat(const Cat &copy);
	 Cat &operator=(const Cat &copy);
	 ~Cat() override;

	 void makeSound() const override;
};
