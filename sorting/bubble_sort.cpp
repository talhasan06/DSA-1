#include<bits/stdc++.h>

#define fl(i,n) for(int i=0;i<n;i++)

using namespace std;

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;

}

void bubbleSort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
        
    }
    
}

void printArray(int arr[],int n){
    fl(i,n){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={5,1,4,2,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    printArray(arr,n);
}