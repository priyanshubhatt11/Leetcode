//https://www.youtube.com/watch?v=rKrLUXfzRQ4
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int dp=0;
        int ans =0;
        for(int i=2;i<n;i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp = 1 + dp;
                ans += dp;
            }
            else{
                dp =  0;
            }
        }
       
        return ans;
    }
};