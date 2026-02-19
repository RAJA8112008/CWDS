#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int direction[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
int n;
int m;
bool isBound(int i,int j){
    return i>=0 && j>=0 && i<n && j<m;
}
int solve(vector<vector<int>>&mat,int i,int j){
    int result=1;
    for(auto dir:direction){
        int ni=i+dir[0];
        int nj=j+dir[1];
        if(isBound(ni,nj) && mat[i][j]<mat[ni][nj]){
            result=result+solve(mat,ni,nj);
        }
    }
    return result;
}
int LongestPath(vector<vector<int>>&mat){
    n=mat.size();
    m=mat[0].size();
   int ans=0;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
             ans+=solve(mat,i,j);
    }
   }
return ans;
}
int main(){
    cout<<"Enter the Row size "<<endl;
    int row;
    cin>>row;
    cout<<"Enter the Col size "<<endl;
    int col;
    cin>>col;
    vector<vector<int>>mat(row,vector<int>(col));
   cout<<"Enter the values in matrix "<<endl;
   for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        int val;
        cin>>val;
        mat[i][j]=val;
    }
   }
   cout<<"Actual Matrix is :"<<endl;
   for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        cout<<mat[i][j]<<" ";
    }cout<<endl;
   }
  cout<<LongestPath(mat)<<endl;
}