#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int IdxExtraSpace(vector<int>&a,vector<int>&b){
    //Unordered map ceation
    unordered_map<int,int>mp;
    //insertion of value of vector a
    for(int i=0;i<a.size();i++){
        mp[a[i]]=i;
    }
    //remove of similar data
    for(int i=0;i<b.size();i++){
        if(mp.find(b[i])!=mp.end()){
            mp[b[i]]=-1;
        }
    }
    //traverse on map 
    for(auto val:mp){
        if(val.second!=-1){
            return val.second;
        }
    }
    return -1;
}
int main(){
    cout<<"Enter the size of a"<<endl;
    int n;
    cin>>n;
    vector<int>a(n);
    
    cout<<"Enter the size of b"<<endl;
    int m;
    cin>>m;
    vector<int>b(m);
    cout<<"Enter values in array a"<<endl;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        a[i]=data;
    }
    cout<<"Enter values in array b"<<endl;
    for(int i=0;i<m;i++){
        int data;
        cin>>data;
        b[i]=data;
    }
    cout<<"Array a is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;

     cout<<"Array b is:"<<endl;
    for(int i=0;i<m;i++){
        cout<<b[i]<<" ";
    }cout<<endl;
    
//INdex of an extra space
int ans=IdxExtraSpace(a,b);
cout<<"Extra element in a index is :"<<ans<<endl;


}