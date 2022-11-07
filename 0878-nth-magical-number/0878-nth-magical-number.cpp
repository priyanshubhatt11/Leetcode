class Solution {
public:
    
    long long gcd(int a, int b){
        if(b == 0)return a;
        return gcd(b, a%b);
    }
    
    long long findlcm(int a, int b){
        
        return (a*b)/gcd(a,b);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        long long l=1, h=1e17, target, mid;
        
        long long lcm = findlcm(a,b);
        
        while(l<h){
            mid = (l+h)/2;
            target = (mid/a) + (mid/b) - (mid/lcm);
            if(target < n){
                l = mid+1;
            }
            else{
                h = mid;
            }
        }
        return h%1000000007;
    }
};