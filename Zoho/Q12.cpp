#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>&mat){
    //creation of stack which will store all memebers present in party
    stack<int>st;
    int n=mat.size();
    for(int i=0;i<n;i++){
        st.push(i);//becouse member will start from 0
    }

    //becouse this process will continue till 1 size of satck(that may be celebrity)
    while(st.size()>1){
        //remove two elements from the stack and then check 
    //if someone b/w them he is not a celebrity
    int a=st.top();
    st.pop();//first member
    int b=st.top();
    st.pop();//second member
    //check if someone know 
         if(mat[a][b]==1){//if a knows b then a is not celebrity then push b into stack
        st.push(b);
    }else{
        st.push(a);
    }

    }
   //single one member will be present in stack means it may be celebrity 
   //then check if know someone or not
   int final=st.top();
   //check in row is know someone if yes then it is not celebrity
   for(int i=0;i<n;i++){
    if(i!=final && mat[final][i]!=0){//(i!=final) means each porson know himself  ,(mat[i][final]!=1)means  col will change and row will same
        return -1;
    }
   }
   //check in col
   for(int i=0;i<n;i++){
    if(i!=final && mat[i][final]!=1){ //mat[final][i]!=1 means each member know final member
        return -1;
    }
   }
   return final;

}
int main(){
    cout<<"Enter the row size "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the col size "<<endl;
    // 2D vector creation
    int m;
    cin>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    cout<<"Enter values in 2D array"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int data;
            cin>>data;
            arr[i][j]=data;
        }
    }
    cout<<"Actual 2D array is"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
  //for returning celebrity
  int ans=celebrity(arr);
  cout<<"Celebrity is "<<ans<<endl;
}