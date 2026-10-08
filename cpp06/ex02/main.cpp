#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "--- random objects ---" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base* p = generate();
        std::cout << "pointer:   ";
        identify(p);
        std::cout << "reference: ";
        identify(*p);
        delete p;
    }

    std::cout << "--- known objects ---" << std::endl;
    A a;
    B b;
    C c;
    identify(&a);
    identify(b);
    identify(c);

    std::cout << "--- plain Base (none of A/B/C) ---" << std::endl;
    Base base;
    identify(&base);
    identify(base);
    return 0;
}
