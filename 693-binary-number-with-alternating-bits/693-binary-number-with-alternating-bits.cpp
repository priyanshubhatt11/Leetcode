class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n!=0){
            int prev = n&1;
            n = n>>1;
            if((n&1) == prev)return false;
        }
        return true;
    }
};