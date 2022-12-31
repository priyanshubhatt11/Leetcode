class Solution {
public:
    int n,m, ans=0;
    
    void solve(vector<vector<int>>&grid, int i, int j, vector<vector<bool>>&vis, int c){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || grid[i][j] == -1)return;
        if(grid[i][j] == 2 && c == -1){
            //cout<<c<<" ";
            ans++;
            //return;
        }
        vis[i][j] = true;
        solve(grid, i+1, j, vis, c-1);
        solve(grid, i, j+1, vis, c-1);
        solve(grid, i-1, j, vis, c-1);
        solve(grid, i, j-1 , vis, c-1);
        vis[i][j] = false;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int idx1, idx2;
        n = grid.size();
        m = grid[0].size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    idx1 = i;
                    idx2 = j;
                }
                if(grid[i][j] == 0)c++;
            }
        }
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        solve(grid, idx1, idx2, vis, c);
        return ans;
    }
};