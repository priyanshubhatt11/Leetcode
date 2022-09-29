class Solution {
public:
    
    int ans=0;
    int dfs(vector<vector<int>> &grid, vector<vector<bool>>&vis, int i ,int j){
        if(i < 0 || i>=grid.size() || j< 0 || j>=grid[0].size() || vis[i][j] == true || grid[i][j] == 0)return 0;
      
        int c =1;
        vis[i][j] = true;
         
        c += dfs(grid, vis, i+1,j )
        + dfs(grid, vis, i,j+1 )
        + dfs(grid, vis, i,j-1)
        + dfs(grid, vis, i-1,j);
        return c;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int c = dfs(grid, vis, i, j);
                    ans = max(ans, c);
                }
            }
        }
        return ans;
    }
};