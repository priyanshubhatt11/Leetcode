class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> dp;
        int n = arr.size();
        
        int ans =0;
        for(int i=0;i<n;i++){
            int temp = arr[i] - diff;
            int An =0;
            if(dp[temp] != 0){
                An = dp[temp];
            }
            dp[arr[i]] = 1 + An;
            
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};