#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool matSearch(vector<vector<int>>&matrix,int target){
    int m=matrix.size();
    int n=matrix[0].size();
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(matrix[i][j]==target){
            return true;
        }
    }
  }
  return false;
}
int main(){
    int m,n;
    cout<<"Enter the row no."<<endl;
    cin>>m;
    cout<<"Enter the col no."<<endl;
    cin>>n;
    
    cout<<"Enter the values in matrix"<<endl;
    int data;
vector<vector<int>> matrix(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cin>>matrix[i][j];
        }
    }

    cout<<"Matrix is :"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
  
    int target;
     cout<<"Enter the value to find in Matrix:"<<endl;
     cin>>target;

     cout<<(matSearch(matrix,target)?"Yes":"NO")<<endl;
}
