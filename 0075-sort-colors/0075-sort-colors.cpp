class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, mid = 0, h = n-1;
        int i=0;
        while(i<=h){
            if(nums[i] == 0){
                swap(nums[l], nums[i]);
                l++;
            }
            else if(nums[i] == 2){
                swap(nums[h], nums[i]);
                h--;
                i--;
            }
            i++;
        }
    }
};