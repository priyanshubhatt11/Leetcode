 class Solution {
    public:
    // [-4, -1, 1, 2]
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int dif = INT_MAX;
        int ans=0;
        for(int i=0;i<n-1;i++){
            int start = i+1;
            int end = n-1;
            
            while(start < end){
                //cout<<i<<" "<<start<<" "<<end<<endl;
       
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == target)return sum;
                if(abs(sum - target) < dif){
                    dif = abs(sum - target);
                    ans = sum;
                }
                if(sum < target)start++;
                else end--;
                
            }
        }
        return ans;
    }
};