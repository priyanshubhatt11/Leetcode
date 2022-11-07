class Solution {
public:
    
    bool solve(string s, string p, int i, int j){
        if(j == p.size()) return i == s.size();
        
        if(p[j+1] != '*'){
            if(i<s.size() && (s[i] == p[j] || p[j] == '.')){
                return solve(s, p, i+1, j+1);
            }
        }
        else{
            if(solve(s, p, i, j+2))return true;
            while(i<s.size() && (s[i] == p[j] || p[j] == '.')){
                if(solve(s, p, i+1, j+2))return true;
                else i++;
            }
        }
        return false;
        
    }
    
    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};