#include <iostream>
using namespace std;
void maxHeapify(int A[], int i, int n) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if (left <= n && A[left] > A[i])
        largest = left;
    if (right <= n && A[right] > A[largest])
        largest = right;
    if (largest != i) {
        swap(A[i], A[largest]);

        maxHeapify(A, largest, n);
    }
}
int heapExtractMax(int A[], int& n) {
    if (n < 1) {
        cout<< "heap underflow" << endl;
        exit(1);
    }

    int max = A[0];    // Extract the maximum element
    A[0] = A[n-1];   // Move the last element to the root
    n--;               // Decrease heap size
    maxHeapify(A, 0, n);  // Maintain max heap property
    return max;
}

int main() {
    int A[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Max heap before extraction: ";
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout<<endl;

    int max = heapExtractMax(A, n);
    cout << "Extracted maximum element: " << max <<endl;

    cout << "Max heap after extraction: ";
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout <<endl;
    return 0;
}
