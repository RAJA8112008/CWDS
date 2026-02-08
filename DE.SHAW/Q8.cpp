#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int rowWithMax1s(vector<vector<int>>&arr){
    int maxCount=0;
    int index=-1;
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<m;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i][j]==1)count++;
        }
        if(count>maxCount){
                maxCount=count;
                index=i;
            }
    }
    return index;
}
int main(){
    int row;
    cout<<"Enter the row size:"<<endl;
    cin>>row;
    int col;
    cout<<"Enter the col size:"<<endl;
    cin>>col;
    vector<vector<int>>arr(row,vector<int>(col));
    cout<<"Enter the values in array:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int val;
            cin>>val;
            arr[i][j]=val;
        }
    }
    cout<<"2D Array is :"<<endl;
        for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl; 
    }
    cout<<rowWithMax1s(arr)<<endl;
}