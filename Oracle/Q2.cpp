#include<iostream>
using namespace std;
bool isPowerofTwo(int n){
    //return false if number is zero or less then zero
        if(n<=0)return false;
        return ((n&(n-1))==0);
}
int main(){
    int n;
    cout<<"Enter the number to find power of 2:"<<endl;
    cin>>n;
    cout<<(isPowerofTwo(n)?"Yes":"NO")<<endl;
}