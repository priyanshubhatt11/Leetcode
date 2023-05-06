class Solution {
public:
    
    long long powFun(long long n, long long x, long long m){
        if(x == 0)return 1;
        long long ss = powFun(n, x/2, m)%m;
        if(x%2 == 1){
            return (ss * ss * n) %m;
        }
        else return (ss * ss)%m;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        long long mod = 1e9+7;
        long long n = nums.size();
        long long ans=0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            int x = upper_bound(nums.begin(), nums.end() ,target - nums[i]) - nums.begin();
            x--;
            if(x<i)break;
            if(nums[i] + nums[x] <= target){
                //cout<<ans<<" ";
                ans += powFun(2, x-i, mod)%mod;    // take or not take
                ans = ans%mod;
            }
            
        }
        return ans;
    }
};