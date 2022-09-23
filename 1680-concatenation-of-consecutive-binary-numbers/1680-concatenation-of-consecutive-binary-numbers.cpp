#define MOD 1000000007;

class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=0;
        for(int i=1;i<=n;i++){
            int x = i;
            long long c=0;
            while(x!=0){
                x = x>>1;
                c++;
            }
            ans = ans<<c;
            ans = (ans ^ i)%MOD;
        }
        return ans%MOD;
    }
};