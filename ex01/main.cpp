#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("111", 50);
        Form f("222", 40, 30);

        std::cout << b << std::endl; //declaring b
        std::cout << f << std::endl; //sign check, cannot sign cuz no bureu declared

        b.signForm(f); //b sign check, should reject, cause too low

        Bureaucrat c("333", 30); //declaring c
        c.signForm(f); //c sign check, should accept, cause fulfilled requirement

        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
