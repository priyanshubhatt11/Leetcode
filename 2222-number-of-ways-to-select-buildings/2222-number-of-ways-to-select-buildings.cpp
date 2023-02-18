class Solution {
public:
    
    long long solve(string &s, string t){
        long long a=0,b=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == t[2]) c+= b;
            if(s[i] == t[1]) b+= a;
            if(s[i] == t[0]) a+= 1;
        }
        return c;
    }
    
    long long numberOfWays(string s) {
        return solve(s, "101") + solve(s, "010");
    }
};