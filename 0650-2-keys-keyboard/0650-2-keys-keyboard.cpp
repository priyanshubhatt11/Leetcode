class Solution {
public:
    
    int solve(int n, int val, int paste){
        if(val > n)return 1001;
        if(val == n)return 0;
        
        return 1 + min(1+solve(n, 2*val, val), solve(n, val+paste, paste));
    }
    
    int minSteps(int n) {
        if(n == 1)return 0;
        return solve(n, 1, 1) + 1;    
    }
};