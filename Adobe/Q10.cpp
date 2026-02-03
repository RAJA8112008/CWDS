#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Search(int arr[],int size,int key){
    //traverse in Array and find the key
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
        //if not found
    }
    return -1;
}
int main(){
    cout<<"Enter the size of array:"<<endl;
    int n;
    cin>>n;
    int arr[n];
    int value;
    cout<<"Enter the Array values"<<endl;
    for(int i=0;i<n;i++){
        cin>>value;
        arr[i]=value;
    }
    
    cout<<"Array is:"<<endl;
       for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    int key; 
     cout<<"Enter the Key which you want to find in array"<<endl;
    cin>>key;
    int idx=Search(arr,n,key);
    if(idx){
        cout<<"Key found"<<endl;
    }else{
        cout<<"Key not found"<<endl;
    }
}