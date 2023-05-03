//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> par, rank;
    public:
    DisjointSet(int n){
        par.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0;i<=n;i++)par[i] = i;
    }
    
    int findpar(int node){
        if(par[node] == node)return node;
        return par[node] = findpar(par[node]);
    }
    
    void unionByRank(int u,int v){
        u = findpar(u);
        v = findpar(v);
        if(u == v)return;
        if(rank[u] < rank[v])par[u] = v;
        else if(rank[u] > rank[v])par[v] = u;
        else{
            par[u] = v;
            rank[v]++;
        }
    }
};

class Solution
{
	public:
	// Krushkal Algorithm
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans=0;
        DisjointSet ds(V+1);
        vector<pair<int,pair<int,int>>> vec;
        for(int i=0;i<V;i++){
            for(auto node:adj[i]){
                int wt = node[1];
                int u = i; 
                int v = node[0];
                vec.push_back({wt,{u,v}});
            }
        }
        
        sort(vec.begin(), vec.end());
        
        for(auto i:vec){
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;
            if(ds.findpar(u) == ds.findpar(v))continue;
            
            ans += wt;
            ds.unionByRank(u,v);
            
        }
        return ans;
        
        
    }
};


















//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends