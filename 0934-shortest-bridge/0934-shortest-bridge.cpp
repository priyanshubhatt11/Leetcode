class Solution {
public:
    vector<vector<bool>> vis;
    int n,m;
    queue<vector<int>> q;
    void dfs(vector<vector<int>>&grid, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || grid[i][j] == 0)return;
        vis[i][j] = true;
        grid[i][j] = 0;
        q.push({i, j});
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
    
    int bfs(vector<vector<int>>&grid){
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int count =0;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                vector<int> vec = q.front();
                int i = vec[0];
                int j = vec[1];
                
                q.pop();
                for(int k=0;k<4;k++){
                    int r = i+dx[k];
                    int c = j+dy[k];
                    if(r <0 || r>=n || c<0 || c>=m || vis[r][c])continue;
                    vis[r][c] = true;
                    if(grid[r][c] == 1)return count;
                    q.push({r, c});
                }
            }
            count++;
        }
        return -1;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<bool>(m, false));
        
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    flag = true;
                    break;
                }
            }
            if(flag)break;
        }
        
        
        return bfs(grid);
    }
};











