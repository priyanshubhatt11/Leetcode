class Solution {
public:
    
    bool solve(string s, string t){
        vector<int> vec(400, -1);
        for(int i=0;i<s.size();i++){
            if(vec[s[i]]!= -1){
                if(vec[s[i]] != t[i])return false;
            }
            else vec[s[i]] = t[i];
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        return solve(s,t) && solve(t,s);
    }
};