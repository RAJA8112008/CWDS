//transform string
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int transform(string s1,string s2){
    //check both strings have same length or not
    if(s1.length()!=s2.length())return -1;
    //if both strings are have same length but differ strings char then check both strings are anagram or not
    unordered_map<char,int>mp;
    for(auto ch:s1){
        mp[ch]++;
    }

    for(auto ch:s2){
        mp[ch]--;
    }
    //to check freq of each char if any char have 1 freq then return -1 (not anagram)
    for(auto val:mp){
        if(val.second!=0)return -1;
    };
//main work to find minimum tranforms
int i=s1.length()-1;
int j=s1.length()-1;
int count=0;
while(i>=0){
    if(s1[i]==s2[j]){
        j--;
    }else{
        count++;
    }
    i--;
}
return count;
}
int main(){
    cout<<"Enter the First string:"<<endl;
    string s1;
    cin>>s1;
    cout<<"Enter the Second String:"<<endl;
    string s2;
    cin>>s2;
    cout<<"First String :"<<endl;
    for(auto ch:s1){
        cout<<ch<<" ";
    }cout<<endl;

     cout<<"Second String :"<<endl;
    for(auto ch:s2){
        cout<<ch<<" ";
    }cout<<endl;
    cout<<"minimum transforms are:"<<transform(s1,s2)<<endl;
}