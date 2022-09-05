class Solution {
public:
    unordered_map<string ,int>map;
    vector<string> ans;
    void solve(string s,int n){
        if(map[s]!=0){
            return;
        }
        map[s]++;
        if(n < 0)return;
        if(n == 0){
            if(findMinRem(s) == 0){
                ans.push_back(s);
            }
            return;
        }
        for(int i=0;i<s.size();i++){
            
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            solve(left+right, n-1);         
            
        }
        return;
    }
    
    int findMinRem(string s){
        stack<char> st;
    
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])) continue;
            if(s[i] == '(')   st.push('(');
            
            else{
                if(st.size() > 0 && st.top() == '(' ) st.pop();
                else st.push(')');
            }
        }
        
        return st.size();
    }
    
    vector<string> removeInvalidParentheses(string s) {
        
        int n = findMinRem(s);
        solve(s,n);
        return ans;
    }
};