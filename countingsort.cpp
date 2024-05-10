#include <iostream>

void countingSort(int A[], int B[], int n, int k) {
    // Create an array to store counts of occurrences of each element
    int C[k + 1] = {0};

    // Step 1: Count the occurrences of each element in A and store them in C
    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    // Step 2: Update C to contain the actual position of each element in the output array
    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    // Step 3: Build the output array B
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main() {
    int A[] = {21, 51, 31, 1, 22, 32, 2, 33};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 51; // Maximum value in A

    int B[n]; // Output array

    countingSort(A, B, n, k);

    // Printing the sorted array B
    std::cout << "Sorted array B: ";
    for (int i = 0; i < n; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
