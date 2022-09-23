class Solution {
public:
    int hammingDistance(int x, int y) {
        int p = x^y;
        int ct=0;
        while(p != 0)
        {
            ct += p&1;
            p= p>>1;
        }
        return ct;
    }
};