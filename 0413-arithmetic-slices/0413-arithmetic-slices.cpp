class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int l=0, r = 1;
        int ans =0;
        for(int i=1;i<nums.size();i++){
            int diff = nums[l] - nums[r];
            while(i<nums.size()-1 && nums[i] - nums[i+1] == diff){
               
                r++;
                i++;
            }
            //cout<<l<<" "<<r;
            int n = r-l+1;
            if(n>=3){
                n-=2;
                ans += (n*(n+1))/2;
            }    
            l = r;
            r++;
        }
        return ans;
    }
};