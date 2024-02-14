#include <iostream>
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        // Find the minimum element in unsorted array
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
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

    selectionSort(arr, size);

    std::cout << "Sorted array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
