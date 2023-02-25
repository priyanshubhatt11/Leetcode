class Solution {
public:
    
    string solve(string s, int &i){
        int num =0;
        string str = "";
        for(;i<s.size();i++){
            if(s[i] >='0' && s[i] <='9') num = num*10 + (s[i]-'0');
            else if(s[i] == '['){
                string ans = solve(s, ++i);
                for(;num>0;num--) str+=ans;
            }
            else if(s[i] == ']')return str;
            else str += s[i];
            
        }
        return str;
    }
    
    string decodeString(string s) {
        int idx =0;
        return solve(s, idx);
    }
};