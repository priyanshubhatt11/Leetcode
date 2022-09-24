class Solution {
public:
    string toHex(unsigned int num) {
        string hex="";
        vector<char> digits ={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        
        while(num){
            hex.push_back(digits[(0xf & num)]);
            num=num>>4;
        }       
        reverse(hex.begin(),hex.end());
        //reverse(ans.begin(), ans.end());
        if(hex == "")return "0";
        return hex;
    }
};