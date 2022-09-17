class Solution {
public:
    
    // Divide and conqueror
    string solve(string s){
        //cout<<s<<" | ";
        if(s.size() < 2)return "";
        unordered_set<char> set;
        for(int i=0;i<s.size();i++){
            set.insert(s[i]);
        }
        for(int i=0;i<s.size();i++){
            if(set.count(tolower(s[i])) == true && set.count(toupper(s[i])) == true)continue;
            //cout<<"-"<<s;
            
            string left = solve(s.substr(0,i));
            string right = solve(s.substr(i+1));
            
            if(left.size() >= right.size())return left;
            return right;
        }
        return s;
    }
    
    string longestNiceSubstring(string s) {
        return solve(s);
    }
};