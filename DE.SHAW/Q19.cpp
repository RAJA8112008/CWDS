#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>TopologySort(int V,vector<vector<int>>&edges){
    //using BFS
    
    unordered_map<int,vector<int>>adj; 
    //vector to store the Degree of each NODE
    vector<int>inDegree(V,0);
    //Adj creation
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        //Directed Graph
        adj[u].push_back(v);
        //inCrement in inDegree
        inDegree[v]++;
    } 
    //vector to store the topology values
    vector<int>ans;
   //check if any node have inDegree in 0 or not
   queue<int>q;
   for(int i=0;i<V;i++){
    if(inDegree[i]==0){
        q.push(i);
    }
   }
   
   while(!q.empty()){
    int temp=q.front();
    
    q.pop();
     ans.push_back(temp);
   
    //travers on its nbr
    for(auto nbr:adj[temp]){
       inDegree[nbr]--;
       //check degree in 0 or not
       if(inDegree[nbr]==0){
        q.push(nbr);
       }
    }
   }
   return ans;

}
int main(){
    //vectex number is  
    int V=6;
    //Edges  are 
    vector<vector<int>>edges={
         {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };
    vector<int>ans=TopologySort(V,edges);
    //print process
    for(auto val:ans){
        cout<<val<<" ";
    }cout<<endl;

}