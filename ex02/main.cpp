#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    Bureaucrat  boss("Boss", 1);
    Bureaucrat  worker("Worker", 140);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Boom");
    PresidentialPardonForm pres("Ali");

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
