//return all duplicates from array
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>duplicateVal(vector<int>&arr){
    vector<int>ans;
    set<int>s;
    for(int i=0;i<arr.size();i++){
        s.insert(arr[i]);
    }

    for(auto val:s){
        ans.push_back(val);
    }
    return ans;
}
int main(){
    cout<<"Enter the size of array"<<endl;
    int n;
    cin>>n;//2, 2, 3, 3, 7, 5
    vector<int>arr(n);
    cout<<"Enter the duplicate Values"<<endl;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr[i]=data;
    }
    cout<<"Actual array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    vector<int>ans=duplicateVal(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}