#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== Test 1: Valid form construction ===" << std::endl;
    try {
        Form tax("tax", 5, 10);
        std::cout << tax << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    std::cout << "=== Test 2: Invalid form grade ===" << std::endl;
    try {
        Form invalid("invalid", 0, 10);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    std::cout << "=== Test 3: Successful sign ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        Form tax("tax", 5, 10);
        bob.signForm(tax);
        std::cout << tax << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    std::cout << "=== Test 4: Failed sign ===" << std::endl;
    try {
        Bureaucrat lowly("Lowly", 50);
        Form tax("tax", 5, 10);
        lowly.signForm(tax);
        std::cout << tax << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
