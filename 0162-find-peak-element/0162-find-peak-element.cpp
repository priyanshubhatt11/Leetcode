class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l =0, h = nums.size()-1;
        while(l<h){
            int mid1 = (l+h)/2;
            int mid2 = mid1 + 1;
            if(nums[mid1] < nums[mid2]){
                l = mid2;
            }
            else{
                h = mid1;
            }
        }
        return h;
    }
};