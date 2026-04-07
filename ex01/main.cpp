#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("Ali", 50); //declaring b
        Form f("222", 40, 30); //sign check, cannot sign cuz no bureu declared

        std::cout << b << std::endl;
        std::cout << f << std::endl;

        b.signForm(f); //b sign check, should reject, cause too low

        Bureaucrat c("Abu", 30); //declaring c
        c.signForm(f); //c sign check, should accept, cause fulfilled requirement

        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
