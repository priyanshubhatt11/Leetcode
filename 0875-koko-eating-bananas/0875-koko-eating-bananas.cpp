class Solution {
public:
    
    long long solve(vector<int>&nums, int mid){
        long long c =0;
        if(mid == 0)return INT_MAX;
        for(auto i:nums){
            if(i%mid != 0){ c++;}
            c += i/mid;
        }
        //cout<<c<<" ";
        return c;
    }
    
    int minEatingSpeed(vector<int>& nums, int tar) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, h = nums[n-1];
        while(l<h){
            long long mid = l + (h-l)/2;
            
            if(solve(nums, mid) <= tar){
                h = mid;
            }
            else l = mid+1;
        }
        return h;
    }
};