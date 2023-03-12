class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> vec;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j] == nums[j-1])continue;
                int l = j+1, h = n-1;
                while(l<h){
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[h];
                    if(sum == tar){
                        vec.push_back({nums[i], nums[j], nums[l], nums[h]});
                        while(l<h && nums[l] == nums[l+1])l++;
                        while(l<h && nums[h] == nums[h-1])h--;
                        l++;
                    }
                    else if(sum > tar){
                        h--;
                    }
                    else l++;
                }
            }
        }
        return vec;
    }
};