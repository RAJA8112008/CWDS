#include<iostream>
using namespace std;
int BuyAndSellStock(int arr[],int n){
  int result=0;
  for(int i=1;i<n;i++){
    if(arr[i]>arr[i-1]){
      int diff=arr[i]-arr[i-1];
      result+=diff;
    }
  }
  return result;
}
int main(){
  cout<<"Enter the size of array"<<endl;
  int n;
  cin>>n;
  int arr[n];
  cout<<"Enter values in array"<<endl;
  for(int i=0;i<n;i++){
    int val;
    cin>>val;
    arr[i]=val;
  }
  cout<<BuyAndSellStock(arr,n)<<endl;
  //100, 180, 260, 310, 40, 535, 695]
}