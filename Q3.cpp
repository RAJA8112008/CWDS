//bitonic generator sort
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>bitonicGenerator(vector<int>arr){
    vector<int>left;
       vector<int>right;
       for(int i=0;i<arr.size();i++){
           if(i%2==0){
               left.push_back(arr[i]);
           }else{
               right.push_back(arr[i]);
           }
       }
       vector<int>ans;
       sort(left.begin(),left.end());
       sort(right.begin(),right.end());
       reverse(right.begin(),right.end());
       for(int i=0;i<left.size();i++){
           ans.push_back(left[i]);
       }
       for(int i=0;i<right.size();i++){
           ans.push_back(right[i]);
       }
       return ans;
    }
int main(){
    int size;
    cout<<"Enter the size of array"<<endl;
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter values in array"<<endl;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        arr[i]=data;
    }
    cout<<"Array is:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<"Final array:"<<endl;
   vector<int>ans=bitonicGenerator(arr);
   for(int i=0;i<ans.size();i++){
     cout<<ans[i]<<" ";
   }cout<<endl;
}