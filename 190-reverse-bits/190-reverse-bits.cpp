class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans;
        for(int i=0;i<=31;i++){
           ans = ans << 1;
           if(n&1 == 1) // if n&1 == 1 means bit is present in last of n 
           {
               ans = ans | 1;
           }

            n = n>>1;
        }
        return ans;
    }
};