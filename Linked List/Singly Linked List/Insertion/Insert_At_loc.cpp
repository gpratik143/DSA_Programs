#include <iostream>

// Define a Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert an element at a specified position in the linked list
void insertAtPosition(Node*& head, int data, int position) {
    Node* newNode = new Node(); // Create a new node
    newNode->data = data;
    newNode->next = nullptr;

    if (position == 0) {
        // If inserting at the beginning, update the head
        newNode->next = head;
        head = newNode;
    } else {
        // Traverse the list to find the node at the position - 1
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp != nullptr) {
            // Insert the new node at the specified position
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            std::cout << "Invalid position." << std::endl;
            delete newNode; // Free the memory if position is invalid
        }
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
    int elements[] = {1, 2, 3, 5};
    int position, elementToInsert;

    // Insert elements at the beginning of the linked list
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); ++i) {
        insertAtPosition(head, elements[i], i);
    }

    // Print the linked list
    std::cout << "Linked List after insertion: ";
    printList(head);

    // Prompt the user for the position and element to insert
    std::cout << "Enter the position to insert: ";
    std::cin >> position;
    std::cout << "Enter the element to insert: ";
    std::cin >> elementToInsert;

    // Insert the element at the specified position
    insertAtPosition(head, elementToInsert, position);

    // Print the linked list after insertion at the specified position
    std::cout << "Linked List after insertion at position " << position << ": ";
    printList(head);

    // Free the memory allocated for the linked list nodes (not shown in this example)

    return 0;
}

