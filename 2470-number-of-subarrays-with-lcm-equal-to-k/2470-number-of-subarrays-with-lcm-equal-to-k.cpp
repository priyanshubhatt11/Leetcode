class Solution {
public:
    
long long gcd(long long int a,long long int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
    
long long lc(int a, int b){
    return (a/gcd(a,b)) *b;
}
     int solve(vector<int> &nums, int k){
        int ans =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            long long prev = nums[i];
            for(int j=i;j<n;j++){
                // prev = ((long long)prev/gcd(prev, nums[j]))*(long long)nums[j];
                prev = lc(prev, nums[j]);
                // long long b = nums[j];
                // prev = prev/gcd(prev,b);
                // prev = prev*b;
                
                if(prev == k)ans++;
               
            }
        }
        return ans;
    }
    
    int subarrayLCM(vector<int>& nums, int k) {
        return solve(nums, k);
    }
};