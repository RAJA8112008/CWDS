//Anagram 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool anagram(string& s1,string& s2){
    //if both strings have differ length 
    if(s1.length()!=s2.length())return false;
    //to storing the freq of each char
    unordered_map<char,int>mp;
    //storing the freq 
    for(auto ch1:s1){
        mp[ch1]++;
    }
    //reducing the counts of char to check is anagram
    for(auto ch2:s2){
        mp[ch2]--;
    }
    //check if any char have freq more then 1
   for(auto val:mp){
    if(val.second!=0)return false;
   }
   return true;
}
int main(){
    cout<<"Enter the  String1:"<<endl;
    string s1;
    cin>>s1;
    cout<<"Enter the  String2:"<<endl;
     string s2;
    cin>>s2;
    //printing the String
     cout<<" the  String first is:"<<endl;
    for(auto ch:s1){
        cout<<ch<<" ";
    }cout<<endl;
     cout<<" the  String second is:"<<endl;
   
    for(auto ch:s2){
        cout<<ch<<" ";
    }cout<<endl;
    
    cout<<(anagram(s1,s2)?"Yes":"NO")<<endl;
}