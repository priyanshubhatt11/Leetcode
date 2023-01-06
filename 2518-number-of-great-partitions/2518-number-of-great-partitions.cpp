#define ll long long
class Solution {
public:
    ll mod = 1e9+7;
    int n;
    vector<vector<int>> dp;
    
    ll solve(vector<int>&nums, int k, int idx, int sum){
        if(idx == n){
            return sum<k;
        }
        if(sum>=k)return 0;
        if(dp[idx][sum] != -1)return dp[idx][sum];
        
        return dp[idx][sum] = (solve(nums, k, idx+1, sum+nums[idx])%mod + solve(nums, k,idx+1, sum)%mod)%mod;
    }
    
    int countPartitions(vector<int>& nums, int k) {
        ll sum=0;
        ll tpart = 1;
        n = nums.size();
        for(int i=0;i<n;i++){
            tpart = (tpart*2)%mod;
            sum += nums[i];
        }
        dp.resize(n, vector<int>(k, -1));
        
        if(sum <2*k)return 0;
        ll count = solve(nums, k, 0, 0);
        //cout<<count<<" ";
        count = (count*2)%mod;
        
        return (tpart - count+mod)%mod;
    }
};