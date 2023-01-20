class Solution {
public:
    set<vector<int>> st;
    int n;
    
    void solve(vector<int>&nums, vector<int>&vec, int idx){
        if(idx >= n){
            return;
        }
        if(vec.back() <= nums[idx]){
            vec.push_back(nums[idx]);
            st.insert(vec);
            solve(nums, vec, idx+1);
            
            vec.pop_back();
            solve(nums, vec, idx+1);
        }
        else solve(nums, vec, idx+1);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
           
        n = nums.size();
        for(int i=0;i<n;i++){
            vector<int> vec;
            vec.push_back(nums[i]);
            solve(nums, vec, i+1);
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
        
        
    }
};