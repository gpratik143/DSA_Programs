#include<iostream>
using namespace std;
int main()
{
    int arr[50],n,element,pos,count=0;
    cout<<"Enter the size of the array:";
    cin>>n;
    cout<<"Enter array elements:";
    for(int i=0;i<n;i++){
        cout<<" ";
        cin>>arr[i];
    }
    cout<<"Enter the elements to be searched:";
    cin>>element;
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            count=1;
            pos=i+1;
            break;
            }
    }
    if(count==0){
        cout<<"Element not found!";
    }
    else{
        cout<<"Element "<<element<<" found at position "<<pos;
    }
    return 0;
}
