class Solution {
public:
    set<vector<int>> st;
    int n;
    
    void solve(vector<int>&nums, vector<int>&vec, int idx){
        if(vec.size()>=2)st.insert(vec);
        
        for(int i=idx;i<n;i++){
            if(vec.empty() || vec.back() <= nums[i]){
                vec.push_back(nums[i]);
                solve(nums, vec, i+1);
                vec.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
           
        n = nums.size();

        vector<int> vec;
        solve(nums, vec, 0);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
        
        
    }
};