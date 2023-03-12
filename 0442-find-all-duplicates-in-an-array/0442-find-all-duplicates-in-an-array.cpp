class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> vec;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int idx = abs(nums[i]) - 1;
            //cout<<idx<<" ";
            
            if(nums[idx] < 0){
                vec.push_back(idx+1);
            }
            else{
                nums[idx] = -nums[idx];
            }
        }
        return vec;
    }
};