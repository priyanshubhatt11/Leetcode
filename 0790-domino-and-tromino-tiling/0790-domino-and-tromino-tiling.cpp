class Solution {
public:
    int numTilings(int n) {
        if(n == 1)return 1;
        if(n == 2)return 2;
        if(n == 3)return 5;
        long long x = 1;
        long long y = 2;
        long long z = 5;
        const int mod = 1e9+7;
        for(int i=4;i<=n;i++){
            long long temp = z;
            z = (z*2+x)%mod;
            x = y;
            y = temp;
        }
        return z;
    }
};