#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));
    
    Bureaucrat  boss("Boss", 1);
    Bureaucrat  worker("Worker", 140);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Boom");
    PresidentialPardonForm pres("Ali");

    std::cout << "\n--- Execute without signing (should throw NotSignedException) ---" << std::endl;
    boss.executeForm(shrub); // shrub is NOT signed yet, so it should fail here

    std::cout <<"\n--- ShrubberyCreationForm ---" << std::endl;
    worker.signForm(shrub); // succeed
    worker.executeForm(shrub); // fail - grade too low
    boss.executeForm(shrub); // succeed

    std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
    boss.signForm(robot); // succeed
    boss.executeForm(robot); // succeed

    std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
    boss.signForm(pres); // succeed
    boss.executeForm(pres); // succeed

    return (0);
}
