#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstRepeated(vector<int>&arr){
    //to store freq
    unordered_map<int,int>freq;
    for(int i=0;i<arr.size();i++){
        freq[arr[i]]++;
    }
    //take first element of array and then find in map having freq more then 2 or not
    for(int i=0;i<arr.size();i++){
        if(freq[arr[i]]>1){
            return i+1;
        }
    }
    return -1;  // if not have twice freq then return -1
}
int main(){
    int n;
    cout<<"Enter the array size :"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the values in array "<<endl;
    int data;
    for(int i=0;i<n;i++){
      cin>>data;
      arr[i]=data;
    }
    cout<<"Array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    //find first element index(starts with 1-index) which have feq 2
      cout<<"Index of twice freq starts is :"<<(firstRepeated(arr))<<endl;

}