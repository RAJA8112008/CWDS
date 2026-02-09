#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>missrepeat(vector<int>&arr){
    int n=arr.size();
    //creation of vector which will store freq of array
    vector<int>freq(n+1,0);//initilize with zero first
    for(int i=0;i<n;i++){
   freq[arr[i]]++;
    }

    //start the freq from 1 index
    int misselem=-1;
    int repelem=-1;
    for(int i=1;i<=n;i++){
        if(freq[i]==2){
            repelem=i;//it stores value  having repetation
        }
        if(freq[i]==0){
            misselem=i;//it stores the missing elem
        }
    }
    return {repelem,misselem};
}
int main(){
    int size;
    cout<<"Enter the size of array:"<<endl;
    cin>>size;
    //creation of vector
    vector<int>arr(size);
    cout<<"Enter the values in array :"<<endl;
    int data;
    for(int i=0;i<size;i++){
        cin>>data;
        arr[i]=data;
    }
    cout<<"Array is:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    //creation of array (missing and repetation valus)
    vector<int>ans=missrepeat(arr);
    cout<<"Missing and doubly freq elem are :"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}