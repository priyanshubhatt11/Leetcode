class Solution {
public:
    //Moore Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int x;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(c == 0){
                x = nums[i];
            }
            
            if(x == nums[i]) c++;
            else c--;
        }
        return x;
    }
};