#include <iostream>

// Define a Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert an element at the end of the linked list
void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(); // Create a new node
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        // If the list is empty, make the new node as the head
        head = newNode;
    } else {
        // Traverse the list to find the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Insert the new node at the end
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr; // Initialize an empty linked list
    int elements[] = {1, 2, 3, 4, 5};

    // Insert elements at the end of the linked list
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); ++i) {
        insertAtEnd(head, elements[i]);
    }

    // Print the linked list
    std::cout << "Linked List after insertion: ";
    printList(head);

    // Free the memory allocated for the linked list nodes (not shown in this example)

    return 0;
}
