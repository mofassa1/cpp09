#pragma once 

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <bits/stdc++.h>
#include <cstring> 

class BitcoinExchange
{
    private:
        std::map<std::string, float> dataBase;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void fillDataBase();
        void findElement(std::string input, float rate);
};
