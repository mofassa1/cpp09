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

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->dataBase = other.dataBase;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->dataBase = other.dataBase;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void    BitcoinExchange::findElement(std::string input , float rate){

    std::map<std::string, float>::iterator it = dataBase.lower_bound(input);

    if (it != dataBase.end() && it->first == input) {
        std::cout << input << " => "<< rate << " = " << rate * it->second << std::endl;

        // std::cout << it->second << std::endl;
    } else {
        if (it == dataBase.begin()) {
            
            throw std::runtime_error("No earlier date available in the database.");
        } else {
            --it;
            std::cout << input << " => "<< rate << "= " << rate * it->second << std::endl;
            // std::cout << it->second << std::endl;
        }
    }
}


void BitcoinExchange::fillDataBase()
{
    std::ifstream dataFile("data.csv");

    if (!dataFile.is_open())
        throw std::runtime_error("Failed to open data File.");

    std::string line;

    std::getline(dataFile, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("syntax error in csv.");

    while (std::getline(dataFile, line)) {
        size_t commaPos = line.find(",");

        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);

        dataBase[date] = std::atof(rateStr.c_str());
    }
    ////////////////////////////////////
    // for(auto ele: dataBase)
    // {
    //     std::cout << ele.first << " " << ele.second << std::endl;
    // }
    ///////////////////////////////////
    dataFile.close();
}
