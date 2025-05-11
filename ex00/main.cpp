#include "BitcoinExchange.hpp"


std::vector<std::string> splitBySpace(const std::string& input) {
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

// int main() {
//     std::string line = "this is a test string";
//     std::vector<std::string> words = splitBySpace(line);

//     for (size_t i = 0; i < words.size(); ++i)
//         std::cout << words[i] << std::endl;

//     return 0;
// }

bool isValidDate(std::string date)
{
    if (date.size() != 10)
        return false;
    if (date[4]  != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7) continue ;

        if (!isdigit(date[i]))
            return false;
    }
    return true;
}

int main(int ac, char **av){

    if (ac != 2)
    {
        std::cout << "invalid  arguiments count " << std::endl;
        return 1;
    }
    try
    {
        
        BitcoinExchange dataBase;
        dataBase.fillDataBase();
        std::ifstream inputFile(av[1]);


        if (!inputFile.is_open())
        {
            std::cerr << "Failed to open File." << std::endl;
            return 1;
        }

        std::string line;
        std::getline(inputFile, line);
        if ("date | value" != line){
            std::cerr << "invalid start line of the file !!!" << std::endl;
            return 1;
        }

        while (std::getline(inputFile, line)) {
            std::vector<std::string> splited = splitBySpace(line);

            if (splited.size() != 3){
                std::cout << "Error: bad input  => " << line << std::endl;
                continue ;
            }
            if (splited[1] != "|"){
                std::cerr << "syntax error !!!" << std::endl;
                continue ;
            }
            if (!isValidDate(splited[0]))
            {
                std::cerr << "Invalid date format !!!" << std::endl;
                continue ;
            }
            float rate = std::atof(splited[2].c_str());

            if (rate < 0){
                std::cerr << "Error: not a positive number." << std::endl;
                continue ;
            }

            if (rate > 1000){
                std::cerr << "Error: too large a number." << std::endl;
                continue ;
            }

            dataBase.findElement(splited[0], rate);
        }

        inputFile.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
