#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>nexGreaterElem(vector<int>&arr){
    stack<int>st;
    int n=arr.size();
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
int main(){
    cout<<"Enter the size of array:"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter values in array"<<endl;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr[i]=data;
    }
    cout<<"Actual array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    vector<int>ans=nexGreaterElem(arr);
    cout<<"Next Greater elements are:"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}