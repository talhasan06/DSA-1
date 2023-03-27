#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    
    int mid=start+(end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }

        mid=start+(end-start)/2;
    }
    return -1;
}
// reverse order
int reverseBinary(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    
    int mid=start+(end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            end=mid-1;
        }else{
            start=mid+1;
        }

        mid=start+(end-start)/2;
    }
    return -1;
}
// first occurance
int firstOccur(int arr[],int size,int key){
    int start=0;
    int end=size-1;

    int mid=start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        if(arr[mid]==key){
            ans=mid;
            end=mid-1;
        }
        if(key>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}
// last occurance
int lastOccur(int arr[],int size,int key){
    int start=0;
    int end=size-1;

    int mid=start+(end-start)/2;
    int res=-1;
    while(start<=end){
        if(arr[mid]==key){
            res=mid;
            start=mid+1;
        }
        if(key>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return res;
}
int main() {
    int arr[]={1,1,1,3,3,3};
    // int res=binarySearch(arr,5,2);
    // cout<<res<<endl;
    // cout<<reverseBinary(arr,5,10);
    // cout<<firstOccur(arr,8,4)<<endl;
    cout<<lastOccur(arr,6,3)<<endl;
   return 0;
}