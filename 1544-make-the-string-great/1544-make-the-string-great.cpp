class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            if( !st.empty() && ((s[i] + 32) == st.top() || (s[i]-32 == st.top()))){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            
        }
        string str;
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
        
    }
};