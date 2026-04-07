#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45)
{
    _target = target;

    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(0));
        seeded = true;
    }
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
    _target = copy._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this != &src)
        _target = src._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
        throw NotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    std::cout << "* Drilling noises *" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" <<std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
}
