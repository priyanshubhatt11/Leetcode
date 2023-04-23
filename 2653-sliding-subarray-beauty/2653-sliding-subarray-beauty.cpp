class Solution {
public:
    
    int solve(vector<int>&freq, int x){
        int c =0;
        for(int i=0;i<=100;i++){
            c += freq[i];
            if(c >= x){
                if(i > 50)return 0;
                return i-50;
            }
        }
        return 0;
    }
    
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> freq(101, 0);
        vector<int> ans;
        
        for(int i=0;i<k;i++){
            freq[nums[i] + 50]++;
        }
        ans.push_back(solve(freq, x));
        
        for(int i=k;i<n;i++){
            freq[nums[i-k]+50]--;
            freq[nums[i]+50]++;
            
            ans.push_back(solve(freq, x));
            
        }
        return ans;
    }
};












