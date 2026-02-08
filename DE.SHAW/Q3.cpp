#include<iostream>
using namespace std;
bool isPalindrome(string &st){
     int i=0;
     int j=st.length()-1;
     while(i<j){
        if(st[i]!=st[j]){
            return false;
        }
        i++;
        j--;
     }
     return true;
}
int main(){
    cout<<"Enter the string  "<<endl;
    string st;
    cin>>st;
    cout<<(isPalindrome(st)?"YES":"NO")<<endl;
}