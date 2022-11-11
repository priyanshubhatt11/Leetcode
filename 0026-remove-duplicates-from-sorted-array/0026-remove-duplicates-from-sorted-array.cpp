class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, j=0;
        while(i<nums.size()){
            if(nums[j] < nums[i]){
                swap(nums[i], nums[j+1]);
                j++;
            }
            i++;
        }
        return j+1;
    }
};