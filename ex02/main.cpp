#include "PmergeMe.hpp"
#include <ctime>  // for clock()

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
        

        std::cout << "Before: ";
        for (int i = 1; i < ac; i++)
        {
            std::cout << av[i] << " " ;
        }
        std::cout << std::endl;
        

        std::clock_t startVec = std::clock();
        Perge.sortUsingVector();
        std::clock_t endVec = std::clock();
        double timeVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;


        std::cout << "Using deque:\n";
        std::clock_t startDeque = std::clock();
        Perge.sortUsingDeque();
        std::clock_t endDeque = std::clock();
        double timeDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;
        
        std::cout << "After: ";
        
        Perge.printContainer(1);

        std::cout << "Time to process a range of " << ac -1 << " elements with std::vector :" << timeVec << " us" << std::endl;
        std::cout << "Time to process a range of " << ac -1 << " elements with std::deque :" << timeDeque << " us" << std::endl;


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

