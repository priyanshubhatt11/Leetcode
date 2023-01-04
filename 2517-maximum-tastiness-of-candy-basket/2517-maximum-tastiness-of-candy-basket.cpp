class Solution {
public:
        
    bool check(vector<int>&nums, int mid, int k){
        int i=0;
        k--;
        for(int j=1;j<nums.size();j++){
            if(nums[j] - nums[i] >= mid){
                k--;
                i = j;
            }
        }
        if(k <= 0)return true;
        else return false;
    }
    
    int maximumTastiness(vector<int>& nums, int k) {
        //[1, 2, 5 , 8 , 13 , 21]
        int ans =0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int l = 0, h = nums[n-1];
        while(l<=h){
            int mid = (l+h)/2;
            if(check(nums, mid, k)){
                ans = max(ans, mid);
                l = mid+1;
                //cout<<mid<<" ";
            }
            else h = mid-1;
        }
        
        return ans;
        
    }
};