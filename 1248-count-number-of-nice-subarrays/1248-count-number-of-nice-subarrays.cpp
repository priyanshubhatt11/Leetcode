class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        // changing all even to 0 and odd to 1
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0)nums[i] = 0;
            else{
                nums[i] = 1;
            }
        }
        // Now we only have to count the subarray with sum = k
        
        int j=0,sum=0,ans=0;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum == k){
                ans++;
            }
            if(map.find(sum-k) != map.end()){
                ans += map[sum -k];
            }
            map[sum]++;
        }
        return ans;
    }
};