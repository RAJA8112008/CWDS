#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void mergeArray(vector<int>&a,vector<int>&b){
    int m=a.size();
    int n=b.size();
    int i=0;
    int j=m-1;
    while(j>=0 && i<n){
        if(a[j]>b[i]){
            swap(a[j],b[i]);
            j--;
            i++;
        }else{
            break;
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
}
int main(){
    int m,n;
    cout<<"Enter the first array size:"<<endl;
    cin>>m;
    cout<<"Enter the second array size:"<<endl;
    cin>>n;
    vector<int>a(m);
    vector<int>b(n);
    cout<<"Enter the First array Values:"<<endl;
    int s1,s2;
    for(int i=0;i<m;i++){
        cin>>s1;
        a[i]=s1;
    }
     cout<<"Enter the Second array Values:"<<endl;
    for(int i=0;i<n;i++){
         cin>>s2;
         b[i]=s2;
    }
    cout<<"First array a is :"<<endl;
    for(int i=0;i<m;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
    cout<<"second array b is :"<<endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }cout<<endl;
    mergeArray(a,b);
}