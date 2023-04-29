class Solution {
public:
    

    int ans =0;
    
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int count =0;
    
    void solve(vector<vector<int>>&grid, int i,int j, vector<vector<bool>>&vis){
        //cout<<i<<" "<<j<<" "<<count<<endl;
        ans = max(ans, count);

        //if(vis[i][j]) return;
        vis[i][j] = true;
        for(int k=0;k<4;k++){
            int r = i+dx[k];
            int c = j+dy[k];
            if(r<0 || c< 0 || r>= grid.size() || c >= grid[0].size() || vis[r][c] || grid[r][c] == 0)continue;
            //vis[r][c] = true;
            count += grid[r][c];
            solve(grid, r, c, vis);
        }
        
    }
    
    int findMaxFish(vector<vector<int>>& grid) {

        int n = grid.size(), m= grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(grid[i][j] > 0 && !vis[i][j]){
                    count = grid[i][j];
                    solve(grid, i, j, vis);
                }
            }
           
        }

        return ans;
    }
};