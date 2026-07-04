#include "Bureaucrat.hpp"

int main()
{
    // Test 1: Working Bureaucrat
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        
        // This next line should throw!
        bob.incrementGrade(); 
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    // Test 2: Instant Fail Bureaucrat
    try {
        Bureaucrat crash("Crash", 160);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
