class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c =0;
        while(num2!=0){
            num2 = num2 & (num2-1);
            c++;
        }
        int ans = 0;
        for(int i=31;i>=0 && c >0;i--){
            if((num1 & (1<<i)) != 0){
                ans = ans | (1<<i);
                c--;
            }
        }
        //return ans;
        int x =0;
        while(c!=0){
            if((ans & (1<<x)) == 0){
                ans = ans | (1<<x);
                c--;
            }
            x++;
        }
        return ans;
    }
};