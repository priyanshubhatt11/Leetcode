class Solution {
public:
    

    
        int solveSpaceOpt(vector<int> &num){
        int n = num.size();
        vector<int> curRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int  cur= n-1; cur>=0; cur--){
            for(int prev = cur-1;prev >= -1; prev--){
                
                int include = 0;
                if(prev == -1 || num[cur] > num[prev]){
                    include = 1 + nextRow[cur+1];
                } 
                int exclude = nextRow[prev+1];
                
                curRow[prev+1] = max(include, exclude);
            }
            nextRow = curRow;
        }
        return nextRow[0];
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1, -1));
        int n = nums.size();
        
        //return solve(nums, n, 0, -1, dp);  
        //return solveTab(nums);
        return solveSpaceOpt(nums);
    }
};