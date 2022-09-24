class Solution {
public:
    string toHex(unsigned int num) {
        string hex="";
        const char digits[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        
        while(num){
            hex.push_back(digits[(0xf & num)]);
            num=num>>4;
        }       
        reverse(hex.begin(),hex.end());
        return hex==""?"0":hex;
    }
};