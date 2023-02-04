//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // topological sort
        vector<int> ino(V, 0);
        for(int i=0;i<V;i++){
            for(auto j: adj[i]){
                ino[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(ino[i] == 0)q.push(i);
        }
        int c =0;
        while(!q.empty()){
            c++;
            int x = q.front();
            q.pop();
            for(auto i:adj[x]){
                ino[i]--;
                if(ino[i] == 0)q.push(i);
            }
        }
        
        if(c == V)return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends