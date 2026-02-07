#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int smallestSubWithSum(vector<int>&arr,int x){
    int n=arr.size();
    int minLen=n+1;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum>x){
                minLen=min(minLen,j-i+1);
                break;
            }
        }
    }
    return (minLen==n+1)?0:minLen;
}
int main(){
    cout<<"Enter the size of array :"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the values in array :"<<endl;
 int data;
    for(int i=0;i<n;i++){
     cin>>data;
     arr[i]=data;
    }

    cout<<"Array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    int x;
    cout<<"Enter the Number for subArray sum"<<endl;
    cin>>x;
    cout<<"SubArray size is "<<(smallestSubWithSum(arr,x))<<endl;


}