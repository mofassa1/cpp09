#pragma once

#include <stack>
#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <cstring> 


class RPN
{
    private:
        std::stack <int> stck;
        std::string arguiments;

    public:
        RPN();
        RPN(std::string args);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        void calculation();
        ~RPN();
};
