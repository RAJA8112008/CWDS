#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int SumofMiddleElements(vector<int>&arr1,vector<int>&arr2){
    //merging process
    int i=0;
    int m=arr1.size();
    int j=0;
    int n=arr2.size();
    vector<int>ans;
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    //copy remaining elements
    while(i<m){
        ans.push_back(arr1[i]);
            i++;
    }
    while(j<n){
         ans.push_back(arr2[j]);
            j++;
    }
    int firstmid=ans[n];
    int secondmid=ans[n-1];
    return firstmid+secondmid;

}
int main(){
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int>arr1(n),arr2(n);
    int data;
    cout<<"Enter the values in arr1"<<endl;
    for(int i=0;i<n;i++){
        cin>>data;
        arr1[i]=data;
        
    }

        cout<<"Enter the values in arr1"<<endl;
    for(int i=0;i<n;i++){
        cin>>data;
        arr2[i]=data;
        
    }
  cout<<SumofMiddleElements(arr1,arr2)<<endl;

}