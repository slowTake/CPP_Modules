#pragma once

#include <string>
#include <iostream>

class brain;

class animal
{
	protected:
	 std::string type;
	public:
	 animal();
	 animal(const animal &copy);
	 animal &operator=(const animal &copy);
	 virtual ~animal();

	 virtual void makeSound() const = 0;
	 std::string getType() const;
};

class Dog : public animal // Public otherwise defaults to private
{
	private:
	 brain* _brain;
	public:
	 Dog();
	 Dog(const Dog &copy);
	 Dog &operator=(const Dog &copy);
	 ~Dog() override;

	 brain *getBrain() const { return _brain;}
	 void makeSound() const override;
};

class Cat : public animal
{
	private:
	 brain* _brain;
	public:
	 Cat();
	 Cat(const Cat &copy);
	 Cat &operator=(const Cat &copy);
	 ~Cat() override;

	 brain *getBrain() const { return _brain;}
	 void makeSound() const override;
};
