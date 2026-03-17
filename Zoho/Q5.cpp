//bitonic generetaor sort
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>bitonicGenerator(vector<int>&arr){
    //first store even in assending order
    vector<int>even;
    vector<int>odd;
    for(int i=0;i<arr.size();i++){
        if(i%2==0){
            even.push_back(arr[i]);
        }else{
            odd.push_back(arr[i]);
        }
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());
    reverse(odd.begin(),odd.end());
    vector<int>ans;
   
      for(int i=0;i<even.size();i++){
        ans.push_back(even[i]);
    }
    for(int i=0;i<odd.size();i++){
        ans.push_back(odd[i]);
    }
   
return ans;
}
int main(){
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter values in vector:"<<endl;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr[i]=data;
    }
    cout<<"Actul arary is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
//bitonic generator sort 
vector<int>ans= bitonicGenerator(arr);
cout<<"Bitonic Generator  arary is:"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

}