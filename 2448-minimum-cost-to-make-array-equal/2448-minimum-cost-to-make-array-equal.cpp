class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums[i], cost[i]});
        }
        sort(vec.begin(), vec.end());
        
        vector<long long> pref(n, 0);
        pref[0] = vec[0].second;
        
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + vec[i].second;
        }
        long long x = pref[n-1]/2;
        int tar =0;
        for(int i=0;i<n;i++){
            if(pref[i] >= x){
                tar = i;
                break;
            }
        }
        long long ans =0;
        for(int i=0;i<n;i++){
            ans += abs((long long)vec[i].first - vec[tar].first) * vec[i].second;
        }
        return ans;
        
    }
};