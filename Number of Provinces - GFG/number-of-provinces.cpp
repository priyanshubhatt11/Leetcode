//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void solve(vector<int> vec[], vector<bool>&vis, int s){
      if(vis[s])return;
      vis[s] = true;
      for(auto i:vec[s]){
          if(!vis[i]){
              solve(vec, vis, i);
          }
      }
  }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> vec[V];
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=j && adj[i][j] == 1){
                    vec[i].push_back(j);
                    vec[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                solve(vec, vis, i);
                c++;
            }
        }
        return c;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends