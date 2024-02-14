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

    // Function to insert a node at a specified position in the circular linked list
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node;
        newNode->data = value;
        if (position == 1) {
            insertAtBeginning(value);
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1; ++i) {
                temp = temp->next;
                if (temp == head) {
                    cout << "Invalid position!" << endl;
                    return;
                }
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to insert a node at the end of the circular linked list
    void insertAtEnd(int value) {
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
        }
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
    int choice, value, position;

    do {
        cout << "Menu:" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at specified position" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                cll.insertAtPosition(value, position);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 4:
                cout << "Circular Linked List: ";
                cll.display();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

