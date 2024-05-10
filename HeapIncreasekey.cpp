#include <iostream>
#define PARENT(i) ((i) / 2)
using namespace std;
void heapIncreaseKey(int A[], int i, int key) {
    if (key < A[i]) {
        cout<< "New key is smaller than current key" <<endl;
        return;
    }
    A[i] = key;
    while (i > 1 && A[PARENT(i)] < A[i]) {
        swap(A[i], A[PARENT(i)]);
        i = PARENT(i);
    }
}

int main() {
    int A[] = {0,16,14,10,8,7,9,3,2,4,1};
    cout << "Max heap before increasing key: ";
    for (int i = 1; i < sizeof(A) / sizeof(A[0]); ++i)
        cout << A[i] << " ";
    cout <<endl;
    int index = 9;
    int newKey = 15;
    heapIncreaseKey(A, index, newKey);

    cout << "Max heap after increasing key: ";
    for (int i = 1; i < sizeof(A) / sizeof(A[0]); ++i)
        cout << A[i] << " ";
    cout <<endl;

    return 0;
}
