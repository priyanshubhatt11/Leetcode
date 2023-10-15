class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int iD, int vD) {
        int mx = INT_MIN, mi = INT_MAX;
        
        int mxidx = -1, miidx = -1; 
        
        for(int i=iD;i<nums.size();i++){
            if(nums[i-iD] > mx){
                mx = nums[i-iD];
                mxidx = i-iD;
            }
            if(nums[i - iD] < mi){
                mi = nums[i-iD];
                miidx = i-iD;
            }
            
            if(abs(nums[i] - mx) >= vD){
                return {mxidx, i};
            }
            if(abs(nums[i] - mi) >= vD){
                return {miidx, i};
            }
        }
        return {-1,-1};
        
    }
};