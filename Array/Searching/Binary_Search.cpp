#include<stdio.h>
int binary_search(int arr[],int size , int element){
    int low,mid,high;
    low=0;
    high=arr[size-1];
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==element){
                return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(int);
    int element=7;
    int searchindex=binary_search(arr,size,element);
    printf("The element %d was found at position at index %d",element,searchindex);
    return 0;
}
