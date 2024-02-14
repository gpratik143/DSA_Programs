#include <iostream>

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        // Last i elements are already in place, so we don't need to check them again
        for (int j = 0; j < size - i - 1; ++j) {
            // Swap adjacent elements if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int maxSize = 100; // Maximum size of the array
    int arr[maxSize]; // Declare an array
    int size; // Actual size of the array

    // Input the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Input elements of the array
    std::cout << "Enter elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    // Perform bubble sort
    bubbleSort(arr, size);

    // Output the sorted array
    std::cout << "Sorted array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
