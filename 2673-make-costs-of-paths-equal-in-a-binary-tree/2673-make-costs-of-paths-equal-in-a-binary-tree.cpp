class Solution {
public:
    int ans =0;
    
    int solve(int idx, int n, vector<int>&cost){
        if(idx > n)return 0;
        
        int left = solve(idx*2, n, cost);
        int right = solve(idx*2+1, n, cost);
        
        ans += abs(left-right);
        
        return max(left, right) + cost[idx-1];
    }
    
    int minIncrements(int n, vector<int>& cost) {
        solve(1, n, cost);
        return ans;
    }
};