#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>maxOfSubarrays(vector<int>&arr,int k){
   //TLE solution accordinng to the GFG
   int n=arr.size();
   vector<int>ans;
   for(int i=0;i<=n-k;i++){
    int maxi=arr[i];
    for(int j=i;j<i+k;j++){
        maxi=max(maxi,arr[j]);
    }
    ans.push_back(maxi);
   }
  return ans;
}
int main(){
    cout<<"Enter the size of araray:"<<endl;
    int n;
    cin>>n;
    int val;
    cout<<"Enter the values in Array:"<<endl;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>val;
        arr[i]=val;
    }
    cout<<"Enter the value of K :"<<endl;
    int k;
    cin>>k;
    cout<<"Array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    vector<int>ans=maxOfSubarrays(arr,k);
      cout<<"Final Array is:"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

}