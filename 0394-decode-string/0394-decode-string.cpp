class Solution {
public:
    
    string solve(string s, int &i){
        string ans = "";
        while(i<s.size()){
            if(isalpha(s[i])){
                ans += s[i++];
            }
            else if(s[i] == ']'){
                i++;
                return ans;
            }
            else{
                int num =0;
                while(isdigit(s[i])){
                    num = num*10 + s[i]-'0';
                    i++;
                }
                string str = solve(s, ++i); 
                while(num--){
                    ans += str;
                }
            }
        }
        return ans;
    }
    
    string decodeString(string s) {
        int idx =0;
        return solve(s, idx);
    }
};