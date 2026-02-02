#include <bits/stdc++.h>
using namespace std;

string Reverse_Word(string &s){
    vector<string> words;
    string word = "";

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.'){
            if(!word.empty()){
                words.push_back(word);
                word = "";
            }
        } 
        else{
            word += s[i];
        }
    }

    // last word
    if(!word.empty()){
        words.push_back(word);
    }

    // reverse
    reverse(words.begin(), words.end());

    // join with dots
    string ans = "";
    for(int i = 0; i < words.size(); i++){
        ans += words[i];
        if(i != words.size()-1){
            ans += '.';
        }
    }

    return ans;
}

int main(){
    string s = "i.like.this.program.very.much";
    cout << Reverse_Word(s) << endl;
}
