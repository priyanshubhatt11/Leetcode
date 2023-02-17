//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int n ,m;
    vector<vector<bool>> vis;
    
    bool ok(int i, int j, vector<vector<int>>&grid){
        if(i <0 || i>= n || j<0 || j>=m || grid[i][j] == 0 || vis[i][j])return false;
        return true;
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s, pair<int, int> d) {
        
        n = grid.size(), m=grid[0].size();
        vis.resize(n, vector<bool> (m, false));
        
        queue<vector<int>> q;
        q.push({s.first, s.second, 0});
        int x = d.first, y=d.second;
        while(!q.empty()){
            vector<int> vec = q.front();
            q.pop();
            int i = vec[0];
            int j = vec[1];
            int c = vec[2];
            if(i == x && j == y)return c;
            if(ok(i+1, j, grid)){
                q.push({i+1, j, c+1});
                vis[i+1][j] = true;
            }
            if(ok(i-1, j, grid)){
                q.push({i-1, j, c+1});
                vis[i-1][j] = true;
            }
            if(ok(i, j+1, grid)){
                q.push({i, j+1, c+1});
                vis[i][j+1] = true;
            }
            if(ok(i, j-1, grid)){
                q.push({i, j-1, c+1});
                vis[i][j-1] = true;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends