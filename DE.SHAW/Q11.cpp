#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int MaxProd(vector<int>&arr){
    int n=arr.size();
    int maxProd=arr[0];
    int minProd=arr[0];
    int ans=arr[0];
    for(int i=1;i<n;i++){
      if(arr[i]<0){
        swap(maxProd,minProd);
      }
      minProd=min(minProd*arr[i],arr[i]);
      maxProd=max(maxProd*arr[i],arr[i]);
      ans=max(minProd,maxProd);
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int>arr(n);
  
    cout<<"Enter the  values in Array:"<<endl;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        arr[i]=data;
    }
    //print the array
    cout<<"Array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<MaxProd(arr)<<endl;
}