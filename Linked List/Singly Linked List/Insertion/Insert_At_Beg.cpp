#include<iostream>
using namespace std;

struct Node
{
    public:
    int data;
    Node *next;
};

Node* insertFront(Node** head, int value){

    Node* new_node = new Node();

    // assign data
    new_node->data = value;

    // change the next node of this newNode
    // to current head of Linked List
    new_node->next = *head;

    // new_node should become the new head of Linked List
    *head = new_node;

    cout << "Inserted Item: " << new_node->data << endl;
}

void printList(Node* node){

    cout << "\nLinked List : " ;

    //as linked list will end when Node is Null
    while(node!=NULL){
        cout << node->data << " "; node = node->next;
    }
    cout << endl;
}

int main(){

    Node* head = NULL;

    insertFront(&head,4);
    insertFront(&head,5);
    insertFront(&head,6);
    insertFront(&head,7);
    insertFront(&head,8);
    insertFront(&head,9);

    printList(head);

    return 0;
}
