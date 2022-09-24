class Solution {
public:
    bool hasAlternatingBits(int n) {
        int o=0,z=0;
        while(n!=0){
            if(n&1 == 1){
                if(((n>>1)&1) !=0)return false;
            }
            else{
                if(((n>>1)&1) != 1)return false;
            }
            n = n>>1;
           
        }
        return true;
    }
};