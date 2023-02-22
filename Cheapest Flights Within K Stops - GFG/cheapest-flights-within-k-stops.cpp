//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>> adj[n+1];
        for(auto i:flights){
            adj[i[0]].push_back({i[1], i[2]}); // node, weight
        }
        queue<vector<int>> pq;
        pq.push({0, src, K+1}); // weight, node, k
        vector<int> dist(n+1, INT_MAX);
        dist[src] = 0;
        
        while(!pq.empty()){
            vector<int> vec = pq.front();
            pq.pop();
            int wt = vec[0] , node = vec[1], k = vec[2];
            
            if(k == 0)continue;
            for(auto it:adj[node]){
                if(dist[it.first] > it.second + wt){
                    dist[it.first] = it.second+wt;
                    pq.push({it.second+wt, it.first, k-1});
                }
            }
        }
        if(dist[dst] == INT_MAX)return -1;
        return dist[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends