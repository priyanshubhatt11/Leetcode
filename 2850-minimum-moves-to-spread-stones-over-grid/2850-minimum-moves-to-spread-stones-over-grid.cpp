class Solution {
public:
    
    bool ok(vector<vector<int>>&grid){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j] != 1)return false;
            }
        }
        return true;
    }
    
    int solve(vector<vector<int>>&grid){
        
        if(ok(grid))return 0;
        
        int ans = INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                
                if(grid[i][j] == 0){
                    grid[i][j] = 1;
                    
                    
                    for(int l=0;l<3;l++){
                        for(int m=0;m<3;m++){
                            if(grid[l][m] > 1){
                                grid[l][m]--;
                                
                                ans = min(ans, abs(i-l) + abs(j-m) + solve(grid));
                                
                                grid[l][m]++;
                                
                            }
                        }
                    }
                    grid[i][j] =0;
                }
                
            }
        }
        return ans;
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        int c=0;
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(grid[i][j] != 1)c++;
        
        if(c == 0)return 0;
        return solve(grid);
    }
};