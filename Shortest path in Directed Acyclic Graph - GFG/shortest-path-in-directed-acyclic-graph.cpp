//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void topoSort(vector<pair<int,int>> vec[], int idx, stack<int> &st, vector<bool>&vis){
        vis[idx] = true;
        for(auto i:vec[idx]){
            if(!vis[i.first]){
                topoSort(vec, i.first, st, vis);
            }
        }
        st.push(idx);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> vec[N];
        for(auto i:edges){
            vec[i[0]].push_back({i[1], i[2]});
        }
        vector<bool> vis(N, false);
        stack<int> st;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topoSort(vec, i, st, vis);
            }
        }
        vector<int> dist(N, 10001);
        dist[0] = 0;
        while(!st.empty()){
            int idx = st.top();
            st.pop();
            for(auto i:vec[idx]){
                dist[i.first] = min(dist[i.first], dist[idx] + i.second);
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