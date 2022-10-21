class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() %2 == 0 && nums2.size()%2 == 0)return 0;
        int one =0, two =0;
        for(int i:nums1){
            one ^= i;
        }
        for(int i:nums2){
            two ^= i;
        }
        if(nums1.size() %2 == 0)return one;
        if(nums2.size()%2 == 0)return two;
        return one^two;
    }
};