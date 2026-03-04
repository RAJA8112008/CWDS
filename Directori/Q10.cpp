//Next small element
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>nextSmallerEle(vector<int>&arr){
    vector<int>ans;
       stack<int>st;
       st.push(-1);
       int n=arr.size();
      for(int i=n-1;i>=0;i--){
          int curr=arr[i];
          while(st.top()>=curr){
              st.pop();
          }
          ans.push_back(st.top());
          st.push(curr);
      }
      reverse(ans.begin(),ans.end());
        return ans;
    }
int main(){
    cout<<"Enter the size of array:"<<endl;
    int size;
    cin>>size;
    vector<int>arr(size);
    for(int i=0;i<size;i++){
        int val;
        cin>>val;
        arr[i]=val;
    }
    cout<<"Array is :"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    vector<int>ans=nextSmallerEle(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}