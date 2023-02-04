//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  //https://www.youtube.com/watch?v=2gtg3VsDGyc&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=25
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<vector<int>> vec(V); // reversing direction of edges
        vector<int> ino(V,0);
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                vec[j].push_back(i);
                ino[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(ino[i] == 0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto i:vec[x]){
                ino[i]--;
                if(ino[i] == 0)q.push(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends