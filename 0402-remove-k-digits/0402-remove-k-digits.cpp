class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.size();i++){
            char ch = num[i];
            while(!st.empty() && k>0 && st.top() > ch){
                st.pop();
                k--;
            }
            st.push(ch);
            if(st.size() == 1 && ch == '0') st.pop();
        }
        string ans = "";
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans == "")return "0";
        return ans;
    }
};