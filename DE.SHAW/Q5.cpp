#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int single(vector<int>&arr){
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    for(auto val:mp){
        if(val.second==1){
            return val.first;
        }
    }
    return -1;
}
int main(){
    int size;
    cout<<"Enter the size of array :"<<endl;
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the values in the array :"<<endl;
    int val;
    for(int i=0;i<size;i++){ 
         cin>>val;
        arr[i]=val;
    }

    cout<<"Array is"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<"Single freq ele is : "<<single(arr)<<endl;

}