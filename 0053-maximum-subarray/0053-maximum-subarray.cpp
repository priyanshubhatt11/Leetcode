class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int c=0;
        for(auto i:nums){
            c+=i;
            ans = max(ans, c);
            if(c <0){
                c=0;
            }
        }
        return ans;
        
    }
};