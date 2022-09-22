class Solution {
public:
    int findGCD(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        // return gcd(nums[0], nums[nums.size()-1]);  
        
        int n1 = nums[0];
        int n2 = nums[nums.size()-1];
        while(n1 % n2 !=0){
            int rem = n1 % n2;
            n1 = n2;
            n2 = rem;
        }
        return n2;
    }
};