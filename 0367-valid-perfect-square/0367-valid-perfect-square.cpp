class Solution {
public:
    bool isPerfectSquare(int num) {
       //  if(num == 1)return true;
       //  for(int i=num/2;i>=2;i--){
       //     //long long m=(long long)i*i;
       //     long long m = i;
       //     //m = m * m;
       //     if(m*m == num)return true;
       // }
       //  return false;
        
        if(num == 1)return true;
        int l=1,r=num/2;
        while(l<=r){
            long long mid = (l+r)/2;
            if(mid * mid == num)return true;
            else if(mid * mid > num)    r = mid-1;
            else l= mid+1;
        }
        return false;
    }
};









