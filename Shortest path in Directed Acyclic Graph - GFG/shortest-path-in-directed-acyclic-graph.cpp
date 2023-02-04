//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    void topoSort(vector<pair<int,int>> adj[], vector<bool> &vis, stack<int> &st, int idx){
        vis[idx] = true;
        for(auto i:adj[idx]){
            if(!vis[i.first]){
                topoSort(adj, vis, st, i.first);
            }
        }
        st.push(idx);
    }
    
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            int d = i[2];
            adj[u].push_back({v,d});
        }
        vector<bool> vis(N,false);
        stack<int> st;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topoSort(adj, vis, st, i);
            }
        }
        vector<int> dist(N, 10001);
        dist[0] = 0;
        while(!st.empty()){
            int u = st.top();
            st.pop();
            for(auto it:adj[u]){
                int v = it.first;
                int d = it.second;
                dist[v] = min(dist[v], dist[u] + d);
            } 
        }
        for(int i=0;i<N;i++){
            if(dist[i] == 10001)dist[i] = -1;
        }
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends