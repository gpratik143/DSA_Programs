#include <iostream>
using namespace std;

//node structure
struct Node {
    int data;
    Node* next;
};

class LinkedList {
  private:
    Node* head;
  public:
    LinkedList(){
      head = NULL;
    }

    //Add new element at the end of the list
    void push_back(int newElement) {
      Node* newNode = new Node();
      newNode->data = newElement;
      newNode->next = NULL;
       if(head == NULL) {
        head = newNode;
      } else {
        Node* temp = head;
        while(temp->next != NULL)
          temp = temp->next;
        temp->next = newNode;
      }
    }

    //reverse the list
    void reverseList() {
     //if(head != NULL) {
        Node* prevNode = head;
        Node* tempNode = head;
        Node* curNode = head->next;

        prevNode->next = NULL;

        while(curNode != NULL) {
          tempNode = curNode->next;
          curNode->next = prevNode;
          prevNode = curNode;
          curNode = tempNode;
        }

        head = prevNode;
    // }
    }

    //display the content of the list
    void PrintList() {
      Node* temp = head;
      if(temp != NULL) {
        cout<<"The list contains: ";
        while(temp != NULL) {
          cout<<temp->data<<" ";
          temp = temp->next;
        }
        cout<<"\n";
      } else {
        cout<<"The list is empty.\n";
        }
    }
};

// test the code
int main() {
  LinkedList MyList;

  //Add five elements in the list.
  MyList.push_back(10);
  MyList.push_back(20);
  MyList.push_back(30);
  MyList.push_back(40);
  MyList.push_back(50);

  //Display the content of the list.
  MyList.PrintList();

  //Reversing the list.
  MyList.reverseList();
  //Display the content of the list.
  MyList.PrintList();

  return 0;
}
