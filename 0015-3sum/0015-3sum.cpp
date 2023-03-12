class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        //-4 -1 -1 0 1 2
        for(int i=0;i<nums.size();i++){
             if( i> 0 && nums[i] == nums[i-1]){
                continue;
             } 
            int x = nums[i];
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = x + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({x, nums[j], nums[k]});
                    
                }
//                 while(j<k && nums[j] == nums[j+1]){
//                         j++;
//                     }
//                 while(k >j && nums[k] == nums[k-1]){
//                     k--;
//                 }
                
                if(sum < 0)j++;
                else k--;
            }
        }
        
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
     
        return ans;
    }
};