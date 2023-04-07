class Solution {
public:
    
    int n ,m, count=0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    void solve(vector<vector<int>>&grid, vector<vector<bool>>&vis, int i, int j){
        vis[i][j] = true;
        //cout<<i<<" "<<j<<endl;
        
        for(int k=0;k<4;k++){
            int r = i + dx[k];
            int c = j + dy[k];
            if(r < 0 || c <0 || r>=n || c>=m || vis[r][c] || grid[r][c] == 0)continue;
            count++;
            solve(grid, vis, r, c);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m= grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || j == 0 || i == n-1 || j==m-1){
                    vis[i][j] = true;
                    if(grid[i][j] == 1){
                        solve(grid, vis, i ,j);
                    }
                }
            }
        }

                
        int ans =0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count =1;
                    solve(grid, vis, i, j);
                    ans += count;
                    
                }
            }
        }
        return ans;
        
    }
};











