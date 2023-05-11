class Solution {
public:
    vector<int> colorTheArray(int nn, vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> ans, vec(nn,0);
        int c=0;
        for(auto &it:nums){
            int idx = it[0], val = it[1];
            if(vec[idx] != 0){
                if(idx > 0 && vec[idx] == vec[idx-1])c--;
                if(idx < nn-1 && vec[idx] == vec[idx+1])c--;
            }
            vec[idx] = val;
            if(idx>0 && vec[idx] == vec[idx-1]) c++;
            if(idx < nn-1 && vec[idx] == vec[idx+1])c++;
            ans.push_back(c);
        }
        return ans;
    }
};