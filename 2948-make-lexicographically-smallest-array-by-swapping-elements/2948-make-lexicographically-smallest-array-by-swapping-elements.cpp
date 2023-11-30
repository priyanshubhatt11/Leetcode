// https://www.youtube.com/watch?v=lDH4lJyhOac
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // making groups of all nums[i] - nums[i-1] <= limit    [1,3,5] [8, 9]
        
        int n = nums.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i], i});
        }
        
        sort(temp.begin(), temp.end());
        
        vector<vector<pair<int,int>>> vec;
        vec.push_back({temp[0]});
        for(int i=1;i<n;i++){
            //if(temp[i].first - vec.back().back().first <= limit){
            // or
            if(temp[i].first - temp[i-1].first <= limit){
                vec.back().push_back({temp[i]});
            }
            else{
                vec.push_back({temp[i]});
            }
        }
        vector<int> ans(n);
        
        // place sorted number in place of sorted indices
        
        for(int i=0;i<vec.size();i++){
            vector<int> vec1, vec2;
            for(auto j:vec[i]){
                vec1.push_back(j.first);
                vec2.push_back(j.second);
            }
            sort(vec2.begin(), vec2.end());
            
            for(int k=0;k<vec2.size();k++){
                ans[vec2[k]] = vec1[k];
            }
        }
        return ans;
        
    }
};