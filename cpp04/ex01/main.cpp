#include "animal.hpp"
#include "brain.hpp"

int main()
{
    std::cout << "--- CREATING ANIMAL ARRAY ---" << std::endl;
    const animal* animals[4];

    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();

    std::cout << "\n--- DELETING ANIMAL ARRAY ---" << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "\n--- DEEP COPY TEST ---" << std::endl;
    
    Dog* originalDog = new Dog();
    originalDog->getBrain()->set_ideas("I love bones", 0);

    std::cout << "Original Dog Idea 0: " << originalDog->getBrain()->get_ideas(0) << std::endl;

    std::cout << "Creating copyDog..." << std::endl;
    Dog* copyDog = new Dog(*originalDog);

    std::cout << "Changing copyDog's idea..." << std::endl;
    copyDog->getBrain()->set_ideas("I love squirrels", 0);

    std::cout << "Original Dog Idea 0: " << originalDog->getBrain()->get_ideas(0) << std::endl;
    std::cout << "Copy Dog Idea 0: " << copyDog->getBrain()->get_ideas(0) << std::endl;

    if (originalDog->getBrain()->get_ideas(0) != copyDog->getBrain()->get_ideas(0))
        std::cout << "\nSUCCESS: Deep Copy confirmed (Brains are independent)!" << std::endl;
    else
        std::cout << "\nFAILURE: Shallow Copy detected (Brains are shared)!" << std::endl;

    delete originalDog;
    delete copyDog;

    return 0;
}