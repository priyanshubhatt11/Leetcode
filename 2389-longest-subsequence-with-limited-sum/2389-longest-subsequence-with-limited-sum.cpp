class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(), nums.end());
        vector<int> pref = nums;
        for(int i=1;i<nums.size();i++){
            pref[i] += pref[i-1];
        }
        vector<int> vec;
        for(auto i:q){
            int xx = upper_bound(pref.begin(), pref.end(), i) - pref.begin();
            vec.push_back(xx);
        }
        return vec;
    }
};