class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans= 0;
        long long c=0;
        for(int i=0;i<s.size();i++){
            if(i == 0 || c <=k){
                c = c*10 + s[i] -'0';
            }
            if(c > k){
                ans++;
                c =0;
                c = c*10 + s[i] - '0';
                if(c > k)return -1;
            }
            //cout<<c<<" ";
        }
        if(c <= k)ans++;
        else ans+=2;
        return ans;
    }
};