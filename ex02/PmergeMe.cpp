#include "PmergeMe.hpp"


int Jacobsthal(int n)
{
    
    if (n == 0 || n == 1)
        return n;

    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void PmergeMe::printContainer(int a)
{

    if (a == 1)
    {
        for(size_t i = 0; i < this->sortedElementsvec.size(); i++)
        {
            std::cout << sortedElementsvec[i] << " " ;
        }
        std::cout << std::endl;
    }
    else if (a == 0)
    {
        for(size_t i = 0; i < this->sortedElementsdeq.size(); i++)
        {
            std::cout << sortedElementsdeq[i] << " " ;
        }
        std::cout << std::endl;
    }
}
////////////////////////////////////////////////

void PmergeMe::sortUsingDeque(){

    mergeSort(decPaired, 0, decPaired.size() - 1);


    std::deque<int> sortedElements;
    std::deque<int> InsortedElements;

    for (size_t i = 0; i < vacPaired.size(); i++)
    {
        sortedElements.push_back(vacPaired[i].first);
        InsortedElements.push_back(vacPaired[i].second);
    }

    size_t inserted = 0;

    size_t last = 1;
    for (size_t i = 2; inserted < InsortedElements.size() ; i++)
    {
        size_t jacob = Jacobsthal(i);
        if (jacob > 0 && jacob - 1 < InsortedElements.size())
        {
            if (InsortedElements[jacob - 1] != -1)
            {
                std::deque<int>::iterator it = std::lower_bound(sortedElements.begin(), sortedElements.end(), InsortedElements[jacob - 1]);
                sortedElements.insert(it, InsortedElements[jacob - 1]);
                // std::cout << "inserting the index jacob : " << jacob - 1 << std::endl;
            }
            inserted++;
        }

        for (size_t j = jacob - 1; j > last && inserted < InsortedElements.size() ; j--)
        {
            if (j - 1 < InsortedElements.size() )
            {
                if (InsortedElements[j - 1] != -1)
                {
                    std::deque<int>::iterator it = std::lower_bound(sortedElements.begin(), sortedElements.end(), InsortedElements[j - 1]);
                    sortedElements.insert(it, InsortedElements[j - 1]);
                    // std::cout << "inserting the index j : " << j - 1 << std::endl;
                }
                inserted++;
            }
        }

        last = jacob ;
    }

    sortedElementsdeq = sortedElements;
    // printContainer(sortedElements, "\nthe result using  deque");
}

////////////////////////////////////////////////


void PmergeMe::sortUsingVector()
{
    mergeSort(vacPaired, 0, vacPaired.size() - 1);

    std::vector<int> sortedElements;
    std::vector<int> InsortedElements;

    for (size_t i = 0; i < vacPaired.size(); i++)
    {
        sortedElements.push_back(vacPaired[i].first);
        InsortedElements.push_back(vacPaired[i].second);
    }

    size_t inserted = 0;

    size_t last = 1;
    for (size_t i = 2; inserted < InsortedElements.size() ; i++)
    {
        size_t jacob = Jacobsthal(i);
        if (jacob > 0 && jacob - 1 < InsortedElements.size())
        {
            if (InsortedElements[jacob - 1] != -1)
            {
                std::vector<int>::iterator it = std::lower_bound(sortedElements.begin(), sortedElements.end(), InsortedElements[jacob - 1]);
                sortedElements.insert(it, InsortedElements[jacob - 1]);

            }
            inserted++;
        }

        for (size_t j = jacob - 1; j > last && inserted < InsortedElements.size() ; j--)
        {
            if (j - 1 < InsortedElements.size() )
            {
                if (InsortedElements[j - 1] != -1)
                {
                    std::vector<int>::iterator it = std::lower_bound(sortedElements.begin(), sortedElements.end(), InsortedElements[j - 1]);
                    sortedElements.insert(it, InsortedElements[j - 1]);
                }
                inserted++;
            }
        }

        last = jacob ;
    }

    sortedElementsvec = sortedElements;
    // printContainer(sortedElements, "\nthe result using vector");

}

PmergeMe::PmergeMe(int ac, char **str)
{
    std::vector<int> data;
    for (int i = 1; i < ac; i++)
    {
        int value = atoi(str[i]);
        if (value < 0)
            throw std::runtime_error("the arguiments should be positive");
        data.push_back(value);
    }
    if (ac % 2 == 0)
        data.push_back(-1);
    for (size_t i = 0; i < data.size(); i += 2)
    {
        std::pair<int, int> Pair ;
        Pair.first = data[i];
        Pair.second =  data[i+1];
        decPaired.push_back(Pair);
        vacPaired.push_back(Pair);
    }
    Inputsize = ac - 1;
}

PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::~PmergeMe()
{
}
