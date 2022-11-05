class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        
        long long ans =0;
        for(int i=0;i<nums.size();i++){
            int x = __gcd(nums[i], k);
            
            for(auto j:map){
                
                if(((long long)x* j.first)%k == 0){
                    ans += j.second;
                }
                // cout<<" '"<<nums[i]<<"' "<<x<<"->";
                // cout<<j.first<<" - "<<j.second<<" "<<ans<<endl;
            }
            //cout<<endl;
            map[x]++;
        }
        return ans;
    }
};