#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>spirallyTraverse(vector<vector<int>>&mat){
int row =mat.size();
       int col=mat[0].size();
       int firstrow=0;
       int firstcol=0;
       int lastrow=row-1;
       int lastcol=col-1;
       int total = row*col;
       int count=0;
       vector<int>ans;
       while(count<total){
           //first row 
           for(int i=firstcol;i<=lastcol && count<total;i++){
               ans.push_back(mat[firstrow][i]);
               count++;
           }
           firstrow++;
           //lastcol
           for(int i=firstrow;i<=lastrow  && count<total;i++){
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
           //firstcol
           for(int i=lastrow;i>=firstrow && count<total;i--){
               ans.push_back(mat[i][firstcol]);
               count++;
           }
           firstcol++;
       }
       return ans;
}
int main(){
    int m;
    cout<<"Enter the row number "<<endl;
    cin>>m;
    int n;
    cout<<"Enter the col number "<<endl;
    cin>>n;
    vector<vector<int>>mat(m,vector<int>(n));

//enter the value in matrix
      cout<<"Enter the data in Matrix"<<endl;
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>mat[i][j];
        
    }
   }

   //print the matrix
   cout<<"Matrix is "<<endl;
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cout<<mat[i][j]<<" ";
    }cout<<endl;
   }
   //print the single array data
    vector<int>ans=spirallyTraverse(mat);
   cout<<"Spcial  Array is "<<endl;
   for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
   }cout<<endl;

}