#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string args): arguiments(args)
{
}

RPN::RPN(const RPN& other) : arguiments(other.arguiments) {
    stck = other.stck; 
}


RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        arguiments = other.arguiments;
        stck = other.stck;
    }
    return *this;
}



void RPN::calculation(){

    std::istringstream iss(arguiments);
    std::string token;

    while (iss >> token) {

        if (token.size() == 1 && !isdigit(token[0]) && stck.size() >= 2)
        {
            int value = stck.top();
            stck.pop();
            if (token == "+")
                value = value + stck.top();
            else if (token == "-")
                value =  stck.top() - value;
            else if (token == "*")
                value =  stck.top() * value;
            else if (token == "/" && value != 0)
                value =  stck.top() / value;
            else
                throw std::runtime_error("invalid opperation !!");
            
            stck.pop();

            stck.push(value);
        }
        else if (token.size() == 1 && isdigit(token[0]))
        {
            int value = atoi(token.c_str());

            stck.push(value);
        }
        else
            throw std::runtime_error("INVALID OPERATION !!");
    }
    if (stck.size() != 1)
        throw std::runtime_error("INVALID operation !!");

    std::cout << stck.top() << std::endl;
}




RPN::~RPN()
{
}

