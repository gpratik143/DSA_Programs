#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the beginning of the circular linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode;
        }
    }

    // Function to delete a node from the beginning of the circular linked list
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "Circular Linked List is empty. Cannot delete from beginning." << endl;
            return;
        }
        Node* temp = head;
        if (temp->next == head) {
            head = nullptr;
        } else {
            Node* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            lastNode->next = head->next;
            head = head->next;
        }
        delete temp;
        cout << "Node deleted from beginning." << endl;
    }

    // Function to delete a node from a specified position in the circular linked list
    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "Circular Linked List is empty. Cannot delete from specified position." << endl;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        int count = 1;
        while (count < position) {
            prev = temp;
            temp = temp->next;
            if (temp == head) {
                cout << "Invalid position. Cannot delete from specified position." << endl;
                return;
            }
            count++;
        }
        if (temp == head) {
            if (temp->next == head) {
                head = nullptr;
            } else {
                Node* lastNode = head;
                while (lastNode->next != head) {
                    lastNode = lastNode->next;
                }
                lastNode->next = head->next;
                head = head->next;
            }
        } else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Node deleted from specified position." << endl;
    }

    // Function to delete a node from the end of the circular linked list
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "Circular Linked List is empty. Cannot delete from end." << endl;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == head) {
            head = nullptr;
        } else {
            prev->next = head;
        }
        delete temp;
        cout << "Node deleted from end." << endl;
    }

    // Function to display the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "Circular Linked List is empty." << endl;
        } else {
            Node* temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
    }
};

int main() {
    CircularLinkedList cll;
    int choice, position;

    do {
        cout << "Menu:" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Delete from beginning" << endl;
        cout << "3. Delete from specified position" << endl;
        cout << "4. Delete from end" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                cll.insertAtBeginning(value);
                break;
            case 2:
                cll.deleteFromBeginning();
                break;
            case 3:
                cout << "Enter position to delete: ";
                cin >> position;
                cll.deleteFromPosition(position);
                break;
            case 4:
                cll.deleteFromEnd();
                break;
            case 5:
                cout << "Circular Linked List: ";
                cll.display();
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

