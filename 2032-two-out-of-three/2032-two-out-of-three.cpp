class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> set;
        for(int i:nums1){
            for(int j:nums2){
                for(int k:nums3){
                    if(i==j){
                        set.insert(i);
                    } 
                    if(j == k){
                        set.insert(j);
                    }
                    if(i == k){
                        set.insert(i);
                    }
                }
            }
        }
        vector<int> ans;
        for(auto i:set){
            ans.push_back(i);
        }
        return ans;
        
        
    }
};