#include <iostream>

// Node structure for linked lists
struct Node {
    float data;
    Node* next;
};

// Insertion Sort for sorting individual buckets
void insertionSort(Node* &bucket) {
    if (bucket == nullptr || bucket->next == nullptr) return;

    Node *sorted = nullptr;
    Node *current = bucket;
    while (current != nullptr) {
        Node* next = current->next;
        if (sorted == nullptr || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    bucket = sorted;
}

void bucketSort(float A[], int n) {
    // Create an array of n pointers to linked lists
    Node** B = new Node*[n];
    for (int i = 0; i < n; i++) {
        B[i] = nullptr;
    }

    // Step 1: Distribute the input values into the buckets
    for (int i = 0; i < n; i++) {
        int index = n * A[i];

        // Create a new node
        Node* newNode = new Node;
        newNode->data = A[i];
        newNode->next = nullptr;

        // Insert the new node into the bucket
        if (B[index] == nullptr) {
            B[index] = newNode;
        } else {
            Node* current = B[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Step 2: Sort each bucket using Insertion Sort
    for (int i = 0; i < n; i++) {
        insertionSort(B[i]);
    }

    // Step 3: Concatenate lists together in order and update the input array
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node* current = B[i];
        while (current != nullptr) {
            A[index++] = current->data;
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Free the memory allocated for the array of pointers
    delete[] B;
}

int main() {
    float A[] = {0.72, 0.64, 0.24, 0.35, 0.82, 0.28, 0.89, 0.53, 0.69, 0.11};
    int n = sizeof(A) / sizeof(A[0]);

    // Perform Bucket Sort
    bucketSort(A, n);

    // Print the sorted array
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
