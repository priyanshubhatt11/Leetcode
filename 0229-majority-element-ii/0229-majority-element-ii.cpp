class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int nums1 = -1, nums2 = -1, c1=0, c2 =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums1 == nums[i])c1++;
            else if(nums2 == nums[i]) c2++;
            else if(c1 == 0){
                nums1 = nums[i];
                c1++;
            }
            else if(c2 == 0){
                nums2 = nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1 =0, c2=0;
        for(int i:nums){
            if(i == nums1)c1++;
            else if(i == nums2)c2++;
        }
        vector<int> vec;
        if(c1 > n/3)vec.push_back(nums1);
        if(c2 > n/3)vec.push_back(nums2);
        return vec;
    }
};