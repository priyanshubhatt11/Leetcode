class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0, c=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0)c++;
            
            while(c >k){
                if(nums[j] == 0)c--;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};