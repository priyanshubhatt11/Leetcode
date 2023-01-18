class Solution {
public:
    
    int maxKadane(vector<int>&nums){
        int ans = INT_MIN;
        int sum=0;
        for(auto i:nums){
            sum += i;
            if(sum < 0)sum=0;
            ans = max(ans, sum);
        }
        return ans;
    }
    int minKadane(vector<int>&nums){
        int ans = INT_MAX;
        int sum=0;
        for(auto i:nums){
            sum += i;
            if(sum > 0){
                sum=0;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
    bool allneg(vector<int>&nums){
        int c=0;
        for(auto i:nums){
            if(i<0)c++;
        }
        return c == nums.size();
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int mx = maxKadane(nums);
        int mi = minKadane(nums);
        // if all number are negative then kadane does not give right answer
        // So check if all are negative or not
        if(allneg(nums))return *max_element(nums.begin(),nums.end());
        int totalsum = 0;
        for(auto i:nums){
            totalsum+=i;
        }
        int ok = totalsum - mi;
        return max(mx, ok);
    
    }
};


