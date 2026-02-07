#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>sortByfreq(vector<int>&arr){
     //create map to store freq
     unordered_map<int,int>freq;
     for(int i=0;i<arr.size();i++){
        freq[arr[i]]++;
     }
     //sort  the data of array according to the freq 
     sort(arr.begin(),arr.end(),[&](int a,int b){
        if(freq[a]==freq[b])return a<b;
        return freq[a]>freq[b];
     });
     return arr;
}
int main(){
    //Enter the size of array 
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the values in array:"<<endl;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        arr[i]=val;
    }
    cout<<"Sorted array is:"<<endl;
       vector<int>ans=sortByfreq(arr);
       for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
       }cout<<endl;

}