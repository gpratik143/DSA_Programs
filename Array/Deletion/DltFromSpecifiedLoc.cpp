#include <iostream>
using namespace std;
// Function to delete element at a specified index
void deleteElement(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        std::cout << "Invalid index!\n";
        return;
    }
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size;
}

int main() {
    const int maxSize = 100; 
    int arr[maxSize]; 
    int size; 
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    std::cout << "Enter elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    int indexToDelete;
    std::cout << "Enter the index of the element to delete: ";
    std::cin >> indexToDelete;
    deleteElement(arr, size, indexToDelete);
    std::cout << "Array after deleting element at index " << indexToDelete << ":\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
