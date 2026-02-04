 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
bool findTriplate(vector<int>&arr){
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        int j=i+1;
        int k=arr.size()-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum==0){
                return true;
            }else if(sum<0){
                j++;
            }else{
                k--;
            }
        }
    }
    return false;
    
}  
 int main(){
   cout<<"Enter the size of array:"<<endl;
   int n;
   cin>>n;
   vector<int>arr(n);
   int m;
   cout<<"Enter the values of array:"<<endl;
   
   for(int i=0;i<n;i++){
       cin>>m;
        arr[i]=m;
   }
   cout<<"array is:"<<endl;
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
   cout<<(findTriplate(arr)?"Yes":"No");
 }