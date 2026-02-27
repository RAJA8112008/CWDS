#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string Excel(int n){
   string res="";
   int remi=0;
   while(n>0){
    n--;//to reduce the case of n=26
    remi=n%26;
    //convert reminder to its corresponding char
    char ch=remi+'A';
    //Enter the data in result
    res+=ch;
    //update number
    n=n/26;
   }
reverse(res.begin(),res.end());
return res;

}
int main(){
    cout<<"Enter the Number to change into Excel :"<<endl;
    int n;
    cin>>n;
    string ans=Excel(n);
     for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
     }cout<<endl;
}