class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0,j=0;
        int num =0;
        for(int i=0;i<nums.size();i++){
            while((num & nums[i]) != 0){
                num ^= nums[j]; // XOR , 1^1 =0, excluding nums[j] from num
                j++;
            }
            num |= nums[i]; // | = OR
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};