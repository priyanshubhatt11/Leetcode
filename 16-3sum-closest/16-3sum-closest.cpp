class Solution {
public:
    //-4 -1 1 2
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            int one = nums[i];
            int j= i+1;
            int k=nums.size()-1;
            
            while(j<k){
                int sum = one + nums[j] + nums[k];
                if(sum - target == 0)return sum;
                
                if(abs(sum - target) < diff){
                    diff = abs(sum - target);
                    ans = sum;
                }
                
                if(sum > target)k--;
                else    j++;
            }
        }
        return ans;
    }
};