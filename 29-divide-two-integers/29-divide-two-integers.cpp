class Solution {
public:
    int divide(int d, long long  r) {
        long long ans = d/r;
        if(ans > INT_MAX){
            return INT_MAX;
        }
        else if(ans < INT_MIN){
            return INT_MIN;
        }
        return floor(d/r);
        
    }
};


