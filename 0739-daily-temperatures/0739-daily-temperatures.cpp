class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<int> st;
        st.push(n-1);
        vector<int> vec;
        vec.push_back(0);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && t[st.top()] <= t[i]){
                st.pop();
            }
            if(st.empty())vec.push_back(0);
            else vec.push_back(st.top() - i);

            st.push(i);
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};