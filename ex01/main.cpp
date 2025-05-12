#include "RPN.hpp"



int main(int ac, char **av){

    if (ac != 2){
        std::cerr << "Invalid arguiment count !!" << std::endl;
        return 1;
    }

    try
    {
        RPN rpn(av[1]);
        
        rpn.calculation();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}