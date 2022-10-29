class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> map;
        int mi = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            map[nums[i]] = 1;
        }
        for(int i=1;i<=n+1;i++){
            if(map[i] == 0)return i;
        }
        
        return 0;
    }
};