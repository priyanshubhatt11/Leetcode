class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mm = INT_MAX;
        int ans = 0;
        for(int i=0;i<prices.size();i++){
            mm = min(mm, prices[i]);
            ans = max(ans, prices[i] - mm);
        }
        return ans;
    }
};