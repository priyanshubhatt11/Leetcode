class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = INT_MAX;
        int ans =0;
        for(int i=0;i<prices.size();i++){
            mx = min(mx, prices[i]);
            ans = max(ans, prices[i] - mx);
        }
        return ans;
    }
};