class Solution {
public:
    
    bool static comp(vector<int> &A, vector<int> &B){
        if(A[0] == B[0])return A[1] < B[1];
        return A[0] > B[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), comp);
        
        
        vector<vector<int>> ans;
        for(auto i:nums){
            ans.insert(ans.begin() + i[1], i);
            // for(auto j:ans){
            //     cout<<j[0]<<" "<<j[1]<<endl;
            // }
            // cout<<endl;
        }
        
        return ans;
    }
};