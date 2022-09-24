class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int z=0,one=0,ans=0;
        for(int i=0;i<32;i++){
            z=0,one=0;
            for(int j=0;j<nums.size();j++){
                if((nums[j] & (1<<i)) == 0)z++;
                else    one++;
            }
            
            if(one%3 != 0){
                ans = ans | (1<<i);
            }
        }
        return ans;
    }
};