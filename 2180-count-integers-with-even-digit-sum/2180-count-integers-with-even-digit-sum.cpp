class Solution {
public:
    
    int summ(int n){
        int sum = 0;
        while(n!=0){
            int temp = n%10;
            sum +=n;
            n = n/10;
        }
        return sum;
    }
    
    int countEven(int num) {
        int ans =0;
        for(int i=1;i<=num;i++){
            if(summ(i)%2 == 0){
                ans++;
            }
        }
        return ans;
    }
};