#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>frequencyCount(vector<int>& arr){
    int n=arr.size();
    vector<int>freq(n,0);
    for(int i=0;i<n;i++){
        freq[arr[i]-1]++;
    }
    return freq;
    //2, 3, 2, 3, 5]
}
int main(){
    cout<<"Enter the size of array:"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        arr[i]= val;
    }
    cout<<"Input array is :"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
     cout<<"Actual array is :"<<endl;
    vector<int>ans=frequencyCount(arr);
    for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
    }cout<<endl;
}