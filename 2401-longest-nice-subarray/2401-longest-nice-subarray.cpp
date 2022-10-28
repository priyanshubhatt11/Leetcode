class Solution {    // sliding window
public:
    int longestNiceSubarray(vector<int>& nums) {
        int num =0, ans =0, j=0;
        for(int i=0;i<nums.size();i++){
            while((num & nums[i]) != 0){
                num = num ^ nums[j];    // unset nums[j] bits
                j++;
            }
            num = num | nums[i];
            
            ans = max(ans, i- j+1);
        }
        return ans;
    }
};