class Solution {
public:
    int numRescueBoats(vector<int>& nums, int tar) {
        sort(nums.begin(), nums.end());
        int ans =0;
        int i = 0, j = nums.size()-1;
        while(i<=j){
            if(nums[i] + nums[j] <= tar){
                i++;
                j--;
            }
            else{
                j--;
            }
            ans++;
        }
        return ans;
        
    }
};