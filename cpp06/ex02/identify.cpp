#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

// Randomly creates an A, B or C and returns it as a Base*
// (implicit upcast: Derived* -> Base* is always safe).
Base* generate(void)
{
    switch (std::rand() % 3)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}

// Pointer version: dynamic_cast returns NULL when the object
// is not really of the requested type.
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Reference version: a reference can't be NULL, so a failed
// dynamic_cast throws std::bad_cast instead. std::bad_cast lives in
// <typeinfo>, which is forbidden, so we catch with (...).
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}
    std::cout << "Unknown type" << std::endl;
}
