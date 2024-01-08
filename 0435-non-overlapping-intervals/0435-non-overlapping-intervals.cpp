class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](vector<int> &A, vector<int>&B){
            return A[1] < B[1];
        });
        
        int ans =0;
        int prev = nums[0][1];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i][0] < prev){
                ans++;
            }
            else{
                prev = nums[i][1];
            }
        }
        return ans;
        
        
    }
};

     