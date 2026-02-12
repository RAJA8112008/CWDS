#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>spiralTraversal(vector<vector<int>>&mat){
     int row=mat.size();
     int col=mat[0].size();
     int firstrow=0;
     int lastrow=row-1;
     int firstcol=0;
     int lastcol=col-1;
     int total=row*col;
     int count=0;
    vector<int>ans;//to store the values
     //spiral travese process
     while(count<total){
        //first row 
        for(int i=firstcol;i<=lastcol && count<total;i++){
            ans.push_back(mat[firstrow][i]);
            count++;
        }
        firstrow++;
        //firstcol
        for(int i=firstrow;i<=lastrow && count<total;i++){
            ans.push_back(mat[i][lastcol]);
            count++;
        }
        lastcol--;
        //lastrow
        for(int i=lastcol;i>=firstcol && count<total;i--){
             ans.push_back(mat[lastrow][i]);
            count++;
        }
        lastrow--;
        //lastcol
        for(int i=lastrow;i>=firstrow && count<total;i--){
            ans.push_back(mat[i][lastcol]);
            count++;
        }
       firstcol++;
     }
     return ans;
}
int main(){
    int row;
    cout<<"Enter the row size:"<<endl;
    cin>>row;
    int col;
    cout<<"Enter the col size "<<endl;
   cin>>col;
   //creation of 2D array
   vector<vector<int>>mat(row,vector<int>(col));
   //enter the vales in vector
   cout<<"Enter the values:"<<endl;
   for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        int data;
        cin>>data;
        mat[i][j]=data;
    }cout<<endl;
   }
   //vector is :
   cout<<"Vector is:"<<endl;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        cout<<mat[i][j]<<" ";
    }cout<<endl;
}


cout<<"Final matrix is"<<endl;
vector<int>ans=spiralTraversal(mat);

    for(int j=0;j<ans.size();j++){
        cout<<ans[j]<<" ";
    }cout<<endl;
}
