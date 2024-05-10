#include<iostream>
using namespace std;
void heap_max(int arr[],int n)
{
    int maximum;
    maximum=arr[0];
    cout<<"The maximum element in the Heap is:"<<maximum;

}
int main(){
    int n;
    cout<<"Enter the size of the Heap:";
    cin>>n;
    cout<<"Enter the elements in Decreasing order:";
    int arr[n];
    for(int i=0;i<n;i++){
    cin>>arr[i];
    }
    heap_max(arr,n);
}
