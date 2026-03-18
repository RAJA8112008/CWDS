#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>rearrange(vector<int>&arr){
    int n=arr.size();
    vector<int>dummy(n);
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    //copy all values in dummy vector
    for(int i=0;i<n;i++){
        dummy[i]=arr[i];
    }
    //arrangement process
    
    int i=0;
    int j=n-1;
    int k=0;
    while(i<=j){
        //laregt value first '
        arr[k++]=dummy[i++];
        //then insert smaller 
        arr[k++]=dummy[j--];

    }
    return arr;
}
int main(){
    cout<<"Enter the size of array "<<endl;
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the value in array "<<endl;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr[i]=data;
    }
    cout<<"Actual array is :"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    vector<int>ans=rearrange(arr);
    cout<<"Alternate arranged array "<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

}