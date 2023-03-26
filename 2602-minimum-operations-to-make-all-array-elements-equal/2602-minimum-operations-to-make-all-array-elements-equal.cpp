class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        long long n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> pref(n,0);
        pref[0] = nums[0];
        for(int i=1;i<n;i++){
            pref[i] += pref[i-1] + nums[i];
        }
        vector<long long> vec;
        
        for(long long tar:queries){
            long long ans=0;
            int idx = upper_bound(nums.begin(), nums.end() , tar) - nums.begin();
            if(idx == 0 || idx == n){
                ans += abs(pref[n-1] - (tar*n));
            }
            else{
                ans += abs(tar*idx - pref[idx-1]);
                ans += abs(tar*(n-idx) - (pref[n-1] - pref[idx-1]));
            }
            
            vec.push_back(ans);
        }
        return vec;
        
    }
};