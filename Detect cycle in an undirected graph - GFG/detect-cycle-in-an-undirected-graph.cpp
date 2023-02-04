//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool dfs(vector<int> adj[], vector<bool> &vis, int ch, int par){
        vis[ch] = true;
        for(auto i:adj[ch]){
            if(!vis[i]){
                if(dfs(adj, vis, i, ch)) return true;
            }
            else if(i!= par)return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V+1, false);
        for(int i=0;i<V;i++){
            if(!vis[i])
                if(dfs(adj, vis, i, -1))return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends