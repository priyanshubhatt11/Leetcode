class Solution {
public:
    
    int solve(vector<int>&nums, int k){
        int j=0,ans =0, c =0;
        
        for(int i=0;i<nums.size();i++){
            c += nums[i];
            
            while(c > k){
                c -= nums[j];
                j++;
            }
            ans += i-j+1;
        }
        return ans;
        
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        // changing all even to 0 and odd to 1
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0)nums[i] = 0;
            else{
                nums[i] = 1;
            }
        }
        // Now we only have to count the subarray with sum = k
        
        return solve(nums, k) - solve(nums, k-1);
    }
};