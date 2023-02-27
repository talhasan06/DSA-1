#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void selectionSort(int arr[],int n){
    int minIndex;
    for (int i = 0; i < n; i++)
    {
        minIndex=i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            swap(&arr[minIndex],&arr[i]);
        }
        
    }
    
}

void printArray(int arr[],int n){
    for (int  i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int arr[]={64,25,12,22,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    printArray(arr,n);
    return 0;
}
