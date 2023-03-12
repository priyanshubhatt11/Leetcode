class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int c =0, ans =0;
        
        int n = nums.size();
        if(n<k)return 0;
        for(int i=0;i<k;i++){
            c += nums[i];
        }
        ans = c;
        for(int i=k-1;i>=0;i--){
            //cout<<i<<" "<<n-i+k<<endl;
            c -= nums[i];
            c += nums[n-k+i];
            ans = max(ans, c);            
        }
        return ans;
    }
};