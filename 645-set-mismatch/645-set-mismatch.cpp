class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    
        int temp=0,j=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans(n+1,0);
        for(int i=0;i<nums.size();i++){
            ans[nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(ans[i]==0){
                temp=i;
            }
            if(ans[i]==2){
                j=i;
            }
        }
        return {j,temp};
    }
};