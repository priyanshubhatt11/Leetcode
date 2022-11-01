class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> o, e;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i%2 == 0)e.push_back(nums[i]);
            else{
                o.push_back(nums[i]);
            }
        }
        
        sort(o.begin(), o.end(), greater<int> ());
        sort(e.begin(), e.end());
        
        int i;
        for(i=0;i<o.size();i++){
            ans.push_back(e[i]);
            ans.push_back(o[i]);
        }
        
        // is size of nums is odd
        
        if(n %2 != 0)ans.push_back(e[i]);
        
        return ans;
    }
};