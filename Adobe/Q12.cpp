#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>Sort012(vector<int>&arr,int size){
    int countZeros=0;
    int countones=0;
    int counttwos=0;
    for(int i=0;i<size;i++){
        //store the count of 0 1 2
        if(arr[i]==0){
            countZeros+=1;
        }else if(arr[i]==1){
            countones+=1;
        }else{
            counttwos+=1;
        }
    }
    //creating same size vector
    vector<int>ans(size);
    int idx=0;
    for(int i=0;i<countZeros;i++){
        ans[idx++]=0;
    }
    for(int i=0;i<countones;i++){
        ans[idx++]=1;
    }
    for(int i=0;i<counttwos;i++){
        ans[idx++]=2;
    }
return ans;
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
    vector<int>ans=Sort012(arr,n);
    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    }