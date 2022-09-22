class Solution {
public:
    
    int findgcd(vector<int>& numsDiv){
        int n = numsDiv[0];
        for(int i=1;i<numsDiv.size();i++){
            int m = numsDiv[i];
            while(m > 0){
                int rem = n%m;
                n = m;
                m = rem;
            }
        }
        return n;
    }
    
    int minOperations(vector<int>& nums, vector<int>& numsDiv) {
        int nn = findgcd(numsDiv);
        
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(nn % nums[i] == 0)return i;
        }
        return -1;
    }
};