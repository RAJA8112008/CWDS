#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool twoSum(vector<int>&arr,int target){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int i=0;
    int j=n-1;
    while(i<j){
        int sum=arr[i]+arr[j];
        if(sum==target){
            return true;
        }else if(sum<target){
            i++;
        }else{
            j--;
        }
    }
    return false;
}
int main(){
    cout<<"Enter the size of array:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the values in array"<<endl;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr[i]=data;
    }
    cout<<"Actual array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<"Enter the target "<<endl;
    int target;
    cin>>target;
    cout<<(twoSum(arr,target)?"Yes":"No")<<endl;
}