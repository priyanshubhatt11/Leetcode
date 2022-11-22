class Solution {
public:
    
  //  S1 = "0"
//    Si = S + "1" + reverse(invert(Si - 1))
    
    string solve(string str){
        for(char &i:str){
            if(i == '0')i = '1';
            else i = '0';
        }
        reverse(str.begin(), str.end());
        return str;
    }
    
    char findKthBit(int n, int k) {
        string s = "0";
        n--;
        while(n--){
            s += "1" + solve(s.substr(0,s.size()));
        }
        //cout<<s<<" ";
        return s[k-1];
    }
};