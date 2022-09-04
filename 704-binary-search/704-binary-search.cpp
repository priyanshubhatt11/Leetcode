class Solution {
public:
    
    int binary(vector<int> &nums, int target, int l,int r){
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                
                return mid;
            }
            else if(nums[mid] > target){
                r = mid -1 ;
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        //sort(nums.begin(),nums.end());
        return binary(nums,target,0,nums.size()-1);
    }
};