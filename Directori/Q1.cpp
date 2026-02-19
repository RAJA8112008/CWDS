#include<iostream>
using namespace std;
int Underroot(int n,int m){
    for(int i=1;i<=m;i++){
        int prod=1;
        for(int j=0;j<n;j++){
            prod *=i;
        }
        if(prod==m)return i;
    }
    return -1;
}
int main(){
    cout<<"Enter the value of n "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the value m"<<endl;
    int m;
    cin>>m;
    cout<<Underroot(n,m)<<endl;
}


