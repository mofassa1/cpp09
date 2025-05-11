#include <iostream>
#include <string>
#include <cstring> // for strrchr

int main() {
    std::string path = "folder/subfolder/file.txt";
    
    const char* lastSlash = std::strrchr(path.c_str(), '/');
    
    if (lastSlash != NULL) {
        std::cout << "Last part: " << (lastSlash + 1) << std::endl;
    } else {
        std::cout << "Character not found." << std::endl;
    }

    return 0;
}
