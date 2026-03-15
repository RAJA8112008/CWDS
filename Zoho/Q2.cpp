#include <bits/stdc++.h>
using namespace std;

vector<int> countFreq(vector<int>& arr) {
    int n = arr.size();
    map<int,int> mp;

    // store frequency
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }

    vector<int> result;

    // frequency from 1 to n
    for(int i = 1; i <=mp.size(); i++){
        result.push_back(mp[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {2,3,2,3,5};

    vector<int> ans = countFreq(arr);

    for(int x : ans){
        cout << x << " ";
    }
}