class Solution {
public:
    int n;
    unordered_map<string, bool> mp;
    
    bool solve(string s1, string s2, int n){
        if(s1 == s2)return true;
        else if(s1.size() == 1)return false;
        else if(mp.count(s1+"#"+s2))return mp[s1+"#"+s2];
        
        for(int i=1;i<n;i++){
            bool con1 = solve(s1.substr(0,i), s2.substr(0,i), i) && solve(s1.substr(i,n-i), s2.substr(i,n-i), n-i);
                
            bool con2 = solve(s1.substr(0,i), s2.substr(n-i), i) && solve(s1.substr(i,n-i), s2.substr(0,n-i), n-i);
              
                if(con1 || con2)return mp[s1 + "#" + s2] = true;
                
        }
        return mp[s1 + "#" + s2]= false;
        
    }
    
    bool isScramble(string s1, string s2) {
        n = s1.size();
        return solve(s1,s2,n);
    }
};