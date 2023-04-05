class Solution {
public:
    
    bool ok(vector<int>&nums, int x){
        long long sum =0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] > x){
                sum += nums[i] - x;
            }
            else{
                sum -= min(sum, (long long)x-nums[i]);
            }
        }
        if(sum <= 0)return true;
        return false;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, h = *max_element(nums.begin(), nums.end());
        int ans =0;
        while(l<=h){
            int mid = l + (h-l)/2;
            
            if(ok(nums, mid)){
                ans = mid;
                cout<<mid<<" ";
                h = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};