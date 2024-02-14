#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Function to delete the middle node of a singly linked list
void deleteMiddleNode(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        // Empty list or only one node, cannot delete the middle node
        return;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    // Use the two-pointer technique to find the middle and the previous nodes
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node
    prev->next = slow->next;
    delete slow;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the linked list: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid input. Exiting program." << std::endl;
        return 1;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    // Create the linked list based on user input
    for (int i = 1; i <= n; ++i) {
        if (head == nullptr) {
            head = tail = new ListNode(i);
        } else {
            tail->next = new ListNode(i);
            tail = tail->next;
        }
    }

    std::cout << "Original linked list: ";
    printList(head);

    // Delete the middle node
    deleteMiddleNode(head);

    std::cout << "Linked list after deleting the middle node: ";
    printList(head);

    // Clean up memory (delete all nodes)
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
