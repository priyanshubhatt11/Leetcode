class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mm = 0,left=0,right=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1)left++;
            else{
                int j=i+1;
                
                while(j<nums.size() && nums[j] != 0){
                    right++;
                    j++;
                }
                mm = max(mm, left+right);
                left =0,right=0;
            }
             mm = max(mm, left+right);
            //cout<<left<<" "<<right<<endl;
            
        }
        if(nums.size() == mm)return mm-1;
        return mm;
    }
};