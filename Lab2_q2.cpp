#include <iostream>
#include <cmath>

int main() {
    const int maxSize = 100; 
    int* tempList = new int[maxSize];  
    std::cout << "Enter positive integers (enter a negative integer to finish):" << std::endl;
    int num;
    int size = 0;
    do {
        std::cin >> num;

        if (num >= 0) {
            tempList[size++] = num;
        }

    } while (num >= 0 && size < maxSize);
    bool found = false;
    for (int i = 0; i < size && !found; ++i) {
        for (int j = 0; j < size && !found; ++j) {
            if (i != j && tempList[i] == static_cast<int>(sqrt(tempList[j]))) {
                std::cout << "The number " << tempList[j] << " has a square root of " << tempList[i] << " in the list." << std::endl;
                found = true;
            }
        }
    }
  
    if (!found) {
        std::cout << "No square roots found in the list." << std::endl;
    }

    delete[] tempList; 

    return 0;
}
   