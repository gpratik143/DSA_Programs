
#include<iostream>
using namespace std;
//node structure
struct node{
int data;
node* next;
};
class LinkedList{
private:
    node* head;
public:
    LinkedList(){
    head=NULL;
    }
    void AddNewElement(int NewElement){
    node* newNode=new node();
    newNode->data=NewElement;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        }
        else{
            node* temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newNode;
        }
    }
    void PrintList(){
    node* temp = head;
      if(temp != NULL) {
        cout<<"The list contains: ";
        while(temp != NULL) {
          cout<<temp->data<<" ";
          temp = temp->next;
        }
        cout<<endl;
      } else {
        cout<<"The list is empty.\n";
    }
    }
};
int main() {
  LinkedList MyList;

  //Add three elements at the end of the list.
  MyList.AddNewElement(10);
  MyList.AddNewElement(20);
  MyList.AddNewElement(30);

  //traverse to display the content of the list.
  MyList.PrintList();

  return 0;
}
