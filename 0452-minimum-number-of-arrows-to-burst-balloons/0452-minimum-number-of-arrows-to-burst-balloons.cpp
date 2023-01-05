class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](vector<int>&A, vector<int>&B){
            return A[1] < B[1];
        });
        
        int x = nums[0][1];
        int ans =0;
        for(int i=1;i<nums.size();i++){
            if(nums[i][0] > x){
                ans++;
                x = nums[i][1];
            }
        }
        return ans+1;
    }
};