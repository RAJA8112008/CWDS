#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int idx, int V,
         unordered_map<int, vector<int>>& adj,
         stack<int>& st,
         vector<int>& ans,
         vector<int>& visited) {

    visited[idx] = true;

    for (auto nbr : adj[idx]) {
        if (!visited[nbr]) {
            dfs(nbr, V, adj, st, ans, visited);
        }
    }
    st.push(idx);
}

vector<int> TopoSort(int V, vector<vector<int>>& edges) {
    vector<int> visited(V, 0);
    vector<int> ans;
    stack<int> st;
    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V, adj, st, ans, visited); 
        }
    }

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        ans.push_back(node);
    }

    return ans;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {3, 2},
        {3, 4}
    };

    vector<int> ans = TopoSort(V, edges);
    cout << "Topo Sort is" << endl;
    for (auto val : ans) {
        cout << val << " ";
    }
    cout << endl;
}