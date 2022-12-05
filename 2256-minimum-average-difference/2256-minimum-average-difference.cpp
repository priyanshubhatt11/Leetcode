class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n,0), suff(n,0);
        long long s1 =0, s2 =0;
        for(int i=0;i<n;i++){
            s1 += nums[i];
            s2 += nums[n-i-1];
            pref[i] += s1;
            suff[n-i-1] = s2;
        }
        
        int ans = INT_MAX;
        int x = INT_MAX;
        int idx  = -1;
        for(int i=0;i<n;i++){
            if(i == n-1){
                x = pref[i]/(i+1);
            }
            else {
                x = abs(pref[i]/(i+1) - suff[i+1]/(n-i-1));
            }
            
            if(ans > x){
                ans = x;
                idx = i;
            }
        }
        return idx;
        
    }
};