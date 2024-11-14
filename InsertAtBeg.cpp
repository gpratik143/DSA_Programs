#include<iostream>
using namespace std;

void insertAtBeg(int arr[], int &n , int element){
    for(int i=n;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=element;
    n++;
}
int main(){
    int n;
    cout<<"Enter size of the array:";
    cin>>n;
    int arr[n+1];
    cout<<"Enter array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int newElement;
    cout<<"Enter the new element to insert";
    cin>>newElement;
    insertAtBeg(arr,n,newElement);
    cout<<"Array After insertion:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    return 0;

}