#include<iostream>
using namespace std;
bool solve(int arr[],int n,int i,int target){
    //base cases
    if(target==0)return true;
    //for a single element
    if(i==n ||target<0)return false;
    //with include curr index val or without include curr index val
    return solve(arr,i+1,n,target-arr[i]) || solve(arr,i+1,n,target);
}
bool canPartition(int arr[],int n){
    //find totall sum of array
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    //check sum is Odd 
   if(sum%2!=0)return false;
   //if sum is even

   int i=0; //index to traverse
   int target=sum/2;
   return solve(arr,0,n,target);
}
int main(){
    cout<<"Enter the Array size:"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the Elements in Array:"<<endl;
    int m;
    for(int i=0;i<n;i++){
        cin>>m;
        arr[i]=m;
    }
    cout<<"Real Array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    //check partition is possible or not
    if(canPartition(arr,n)){
        cout<<"YES"<<endl;
    }else{
         cout<<"No"<<endl;
    }
    
}