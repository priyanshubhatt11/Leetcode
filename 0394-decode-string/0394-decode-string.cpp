class Solution {
public:
    // while we not getting closing bracket we add string to temp string and when we get it we return it and append its num times in original string
    string solve(string s, int &i){
        int num =0;
        string str = "";
        for(;i<s.size();i++){
            if(s[i] >='0' && s[i] <='9') num = num*10 + (s[i]-'0');
            else if(s[i] == '['){
                string ans = solve(s, ++i); // ++i because we have done call by reference and with the help of call by reference it will not come to its previous index after return.
                while(num--) str+=ans;  
                num =0; // num become negative so we initialize it to zero so that in next iteration this will not change the value of next num.
            }
            else if(s[i] == ']')return str;
            else str += s[i]; // if s[i] is character.
            
        }
        return str;
    }
    
    string decodeString(string s) {
        int idx =0;
        return solve(s, idx);
    }
};