class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int ans=0;
        bool vis[200001]={0};
        for(auto it: nums)
            vis[it]=1;
        
        for(int i=1;i<=200000;i++)
        {
            int gcd=0;
            for(int j=i;j<=200000;j+=i)
            {
                if(vis[j])
                    gcd=__gcd(gcd,j);
            }
            if(gcd==i)
                ans++;
        }
        
        return ans;
    }
};