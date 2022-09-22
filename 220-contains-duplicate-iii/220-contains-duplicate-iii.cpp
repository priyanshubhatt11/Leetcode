class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int idx, int val) {
        vector<pair<long long, int>> vec;
        int j=0;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i], i});
        }
        
        sort(vec.begin(), vec.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     if(abs(vec[i].first - vec[i+1].first) <= val){
        //         if(abs(vec[i].second - vec[i+1].second) <= idx)return true;
        //     }
        // }
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(vec[i].first - vec[j].first) <= val){
                    if(abs(vec[i].second - vec[j].second) <= idx)return true;
                }
                else{
                    break;
                }
            }
        }
        return false;
    }
};