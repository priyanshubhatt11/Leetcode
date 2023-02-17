//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto i:edges){
            adj[i[0]].push_back({i[2], i[1]}); // weight, node
            adj[i[1]].push_back({i[2], i[0]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 1}); // weight, node;
        vector<int> dist(n+1, INT_MAX);
        dist[1] = 0;
        vector<int> par(n+1);
        for(int i=1;i<=n;i++) par[i] = i;
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto i:adj[node]){
                if(dist[i.second] > wt + i.first){
                    dist[i.second] = wt + i.first;
                    pq.push({wt+i.first, i.second});
                    par[i.second] = node;
                }
            }
        }
        if(dist[n] == INT_MAX)return {-1};
        vector<int> ans;
        int x = n;
        
        while(par[x] != x){
            ans.push_back(x);
            x = par[x];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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