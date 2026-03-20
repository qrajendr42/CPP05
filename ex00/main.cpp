#include "Bureaucrat.hpp"

int main()
{
    try //creating biro fella with grade 5, increase grade to 4 and then decrease to 5
    {
        Bureaucrat b1("Alpha", 5);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << "After increament " << b1 << std::endl;
        b1.decrementGrade();
        std::cout << "After decreament " << b1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;

    try //creating biro with invalid grade cuz too low
    {
        Bureaucrat b2("BadBureaucrat", 151);
        std::cout << b2 << std:: endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception while creating b2: " << e.what() << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;

    try //creating biro with highest grade which is 1 and then try to increase the grade
    {
        Bureaucrat b3("TopRank", 1);
        std::cout << b3 << std::endl;
        b3.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception while increament b3: " << e.what() << std::endl;
    }
    return 0;
}
