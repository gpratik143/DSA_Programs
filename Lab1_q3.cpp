#include <iostream>

int main() {
    const int maxSize = 100; 
    char* tempList = new char[maxSize];
    
    std::cout << "Enter single letters (enter '%' to finish):" << std::endl;

   
    char letter;
    int size = 0;

    do {
        std::cin >> letter;

        if (letter != '%') {
            tempList[size++] = letter;
        }

    } while (letter != '%' && size < maxSize);

    bool found = false;
    for (int i = 0; i < size - 1 && !found; ++i) {
        if (tempList[i + 1] == tempList[i] + 1) {
            std::cout << "Letters " << tempList[i] << " and " << tempList[i + 1] << " appear next to each other alphabetically." << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No letters appear next to each other alphabetically." << std::endl;
    }

    delete[] tempList; 

    return 0;
}
