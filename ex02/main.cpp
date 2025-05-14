#include "PmergeMe.hpp"

int main(int ac , char **av){

    if (ac == 1)
    {
        std::cerr << "No Inputs !!" << std::endl;
        return 1;
    }
    else if (ac == 2)
    {
        std::cerr << "No Sorting Need For One Element " << std::endl;
        return 2;
    }

    try
    {
        PmergeMe Perge(ac, av);
        Perge.sortUsingVector();
        // Perge.mergeSort();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}