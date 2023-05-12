class Solution {
public:
    
    void prevSmaller(vector<int>&h, vector<int>&prev){
        stack<int> st;
        st.push(-1);
        for(int i=0;i<h.size();i++){
            while(st.top()!=-1 && h[st.top()] >= h[i]){
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
    }
    
    void nextSmaller(vector<int>&h, vector<int>&next){
        stack<int> st;
        int n = h.size();
        st.push(n);
        for(int i=n-1;i>=0;i--){
            while(st.top() != n && h[st.top()] >= h[i]){
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
    }
    
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> prev(n);
        prevSmaller(h, prev);
        
        vector<int> next(n);
        nextSmaller(h, next);
        
        int ans =0;
        for(int i=0;i<n;i++){
            ans = max(ans, (next[i] - prev[i] - 1)*h[i]);
        }
        return ans;
        
    }
};