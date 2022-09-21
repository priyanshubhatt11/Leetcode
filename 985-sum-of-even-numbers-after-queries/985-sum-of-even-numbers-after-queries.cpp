class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int sum=0;
        for(int i:nums){
            if(i%2 == 0)sum+= i;
        }
        vector<int> ans;
        for(int i=0;i<q.size();i++){
            int val = q[i][0], idx = q[i][1];
            
            if(nums[idx] %2 == 0){
                sum -= nums[idx];
            }
            
            nums[idx] += val;
            if(nums[idx] %2 == 0){
                sum += nums[idx];
            }
            
            ans.push_back(sum);
        }
        return ans;
    }
};