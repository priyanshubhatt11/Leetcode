class Solution {
public:
    int dp[2001][2001];
    bool solve(string &s, string &p, int idx1, int idx2){
        if(idx1 == s.size() && idx2 != p.size()){   // special case for s = "abc" and p="*************"
            for(int i=idx2;i<p.size();i++){
                if(p[i]!= '*')return false;
            }
            return true;
        }
        if(idx1 == s.size() && idx2 == p.size())return true;
        if(idx1 >=s.size() || idx2>=p.size())return false;
        
        if(dp[idx1][idx2] != -1)return dp[idx1][idx2];
        
        bool ans = false;
        if(s[idx1] == p[idx2] || p[idx2] == '?'){
            ans |= solve(s, p, idx1+1, idx2+1);
        }
        else if(p[idx2] == '*'){
                        
            for(int i=idx1;i<=s.size();i++){
                ans |= solve(s, p, i, idx2+1);
            }
        }
        else{
            return false;
        }
        return dp[idx1][idx2] = ans;
        
    }
    
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(s, p, 0,0);
    }
};