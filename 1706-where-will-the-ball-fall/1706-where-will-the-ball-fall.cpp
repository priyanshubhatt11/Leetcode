class Solution {
public:
    /*
            [ 1 ,  1,  1 , -1, -1]
            [ 1 ,  1,  1 , -1, -1]
            [-1 , -1, -1 ,  1,  1]
            [ 1 ,  1,  1 ,  1, -1]
            [-1 , -1, -1 , -1, -1]
    */
    
    int dfs(vector<vector<int>> &grid, int i, int j){
        if(i >= grid.size())return j;
        
        if(j < grid[0].size()-1 && grid[i][j] == 1 && grid[i][j+1] == 1){
            return dfs(grid, i+1, j+1);
        }
        else if( j > 0 && grid[i][j] == -1 && grid[i][j-1] == -1){
            return dfs(grid, i+1, j-1);
        }
        else{
            return -1;
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        // for(auto i:grid){
        //     for(int j:i)cout<<j<<" ";
        //     cout<<endl;
        // }
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m);  
        for(int j=0;j<m;j++){
            ans[j] = dfs(grid, 0, j);
        }
        return ans;
    }
};