#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<string>>groupAnagrams(vector<string>&strs){



//map creation to find freq
map<string,vector<string>>mp;
//travese on array and find freq and store them
for(auto st:strs){
    string s=st;//storing the current string to compare next st
    sort(s.begin(),s.end());
    mp[s].push_back(st);
}
vector<vector<string>>ans;//to store the final value
//travese on map 
for(auto it=mp.begin();it!=mp.end();it++){
    ans.push_back(it->second);
}
return ans;
}
int main(){
    cout<<"Enter the size of array :"<<endl;
    int n;
    cin>>n;
    vector<string>arr(n);
    cout<<"Enter the stings in Array"<<endl;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr[i]=s;
    }
    cout<<"Array is :"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    //groupAnagrams
    vector<vector<string>>ans=groupAnagrams(arr);
    //ans is 2D array then
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
}cout<<endl;
}
//Input->"eat","tea","tan","ate","nat","bat"
//Output->["bat"],["nat","tan"],["ate","eat","tea"]]
//input may be in any Order