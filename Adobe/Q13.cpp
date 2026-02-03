#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minJumps(vector<int>&arr){
    int maxi=0;
    int choice=0;
    int jumps=0;
    for(int i=0;i<arr.size();i++){
        maxi=max(maxi,arr[i]+i);
        if(i==choice){
            jumps++;
            choice=maxi;
        }
        if(choice>=arr.size()-1)return jumps;
    }
    return -1;
}
int main(){
     cout<<"Enter the Array size:"<<endl;
    int n;
    cin>>n;
   vector<int> arr(n);
    cout<<"Enter the Elements in Array:"<<endl;
    int m;
    for(int i=0;i<n;i++){
        cin>>m;
        arr[i]=m;
    }
    cout<<"Real Array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<minJumps(arr)<<endl;
}