class Solution {
public:
    // 2^10 = (2*2)^5
    
    double solve(double x, int n){
        if(n == 0)return 1;
        //cout<<x<<" "<<n<<endl;
        if(n%2 == 0)return solve(x*x, n/2);
        else return x *solve(x*x, n/2);
    }
    
    double myPow(double x, int n) {
        double ans = solve(x, n);
        return (n>=0)?ans:1/ans;
    }
};