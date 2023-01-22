class Solution {
public:
    vector<vector<string>> ans; 
    
    bool ispalindrome(string s, int l, int h){
        while(l<=h){
            if(s[l++] != s[h--])return false;
        }
        return true;
    }
    
    void solve(string s, vector<string>&vec, int idx){
        if(idx >= s.size()){
            ans.emplace_back(vec);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(ispalindrome(s, idx,i)){
                vec.push_back(s.substr(idx , i-idx+1));
                solve(s, vec, i+1);
                vec.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
       vector<string> vec;
        solve(s, vec, 0);
        return ans;
    }
};