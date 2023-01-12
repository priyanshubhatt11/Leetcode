//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    void solve(vector<vector<char>>&grid, int i,int j, vector<vector<bool>>&vis){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j] || grid[i][j] == '0')return;
        vis[i][j] = true;
        solve(grid, i+1, j, vis);
        solve(grid, i, j+1, vis);
        solve(grid, i-1, j, vis);
        solve(grid, i, j-1, vis);
        solve(grid, i+1, j+1, vis);
        solve(grid, i+1, j-1, vis);
        solve(grid, i-1, j+1, vis);
        solve(grid, i-1, j-1, vis);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    solve(grid, i, j, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends