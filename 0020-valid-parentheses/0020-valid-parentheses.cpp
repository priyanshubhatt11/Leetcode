class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(st.empty() || i == '(' || i == '{' || i == '[')st.push(i);
            else{
                //cout<<i<<" ";
                if(i == ')'){
                    if(i!=(char)(st.top()+1))return false;
                }
                else {
                    if(i!=char(st.top()+2))return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};