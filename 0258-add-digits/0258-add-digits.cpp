class Solution {
public:
    int addDigits(int num) {
        while(true){
            if(num < 10)return num;
            int temp = 0;
            //cout<<num<<" ";
            while(num!=0){
                int x = num%10;
                temp = temp +  x;
                num = num/10;
            }
            num = temp;
        }
        return 0;
    }
};