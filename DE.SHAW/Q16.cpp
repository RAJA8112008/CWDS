#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>&arr){
  //interchange Row and col
  for(int i=0;i<arr.size();i++){
    for(int j=i+1;j<arr[0].size();j++){
        swap(arr[i][j],arr[j][i]);
    }
  }
  //reverse row 
  for(int i=0;i<arr.size();i++){
    reverse(arr[i].begin(),arr[i].end());
  }
 
}

int main(){
    cout<<"Enter the row"<<endl;
    int row;
    cin>>row;
    cout<<"Enter the col"<<endl;
    int col;
    cin>>col;
    //craetion of 2D array
    vector<vector<int>>arr(row,vector<int>(col));
cout<<"insert the value "<<endl;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        int val;
        cin>>val;
        arr[i][j]=val;
    }
}

cout<<"Before Rotation :"<<endl;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        cout<<arr[i][j]<<" ";
    }cout<<endl;
}
//[[1 2 3], [4 5 6], [7 8 9]]
//ans will be in 2D array form
rotate(arr);
cout<<"After rotation :"<<endl;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        cout<<arr[i][j]<<" ";
    }cout<<endl;
}
}