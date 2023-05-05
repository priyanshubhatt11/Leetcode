//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class DisjointSet{
    public:
    vector<int> parent, rank;
    
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node] == node)return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v)return;
        if(rank[u] > rank[v]) parent[v] = u;
        else if(rank[u] < rank[v]) parent[u] = v;
        else{
            parent[u] = v;
            rank[v]++;
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        int m = edge.size();
        if(n>m+1)return -1;
        
        
        DisjointSet ds(n);
        
        for(auto i:edge){
            ds.unionByRank(i[0],i[1]);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i)c++;
        }
        return c-1;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends