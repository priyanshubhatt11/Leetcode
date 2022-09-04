class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;
        int sum ;
        for(int i=0;i<n-1;i++){
            sum =0;
            for(int j=i;j<i+2;j++){
                //cout<<i<<" "<<j<<endl;
                sum += nums[j];
            }
            
            if(map[sum] !=0)return true;
            map[sum]++;
        }
        return false;
    }
};