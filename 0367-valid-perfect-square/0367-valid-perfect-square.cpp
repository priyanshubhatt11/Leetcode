class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)return true;
       for(int i=num/2;i>=2;i--){
           //long long m=(long long)i*i;
           long long m = i;
           //m = m * m;
           if(m*m == num)return true;
       }
        return false;
    }
};