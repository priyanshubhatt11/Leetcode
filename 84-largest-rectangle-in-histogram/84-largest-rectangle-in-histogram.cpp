class Solution {
public:
    
    void previousSmaller(vector<int>&h, vector<int> &ps){
        stack<int> st;      // Storing index
        st.push(-1);
        for(int i=0;i<h.size();i++){
            
            int x = h[i];
            while(st.top() != -1 && h[st.top()] >= x){
                st.pop();
            }
            ps[i] = st.top();
            st.push(i);
        }
    }
    
    void nextSmaller(vector<int>&h, vector<int>& ns){
        stack<int> st;      // storing index
        st.push(h.size());
        
        for(int i=h.size()-1;i>=0;i--){
            int x = h[i];
            while(st.top() != h.size() && h[st.top()] >= x){
                st.pop();
            }
            ns[i] = st.top();
            st.push(i);
        }
        
    }
    
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> ps(n);
        previousSmaller(h, ps);
        
        vector<int> ns(n);
        nextSmaller(h, ns);
        
        //  for(auto i:ps){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i:ns){
        //     cout<<i<<" ";
        // }
        int area = 0;
        for(int i=0;i<n;i++){
            int wth = ns[i] - ps[i] -1;
            //cout<<h[i] *wth<<" ";
            area = max(area , h[i] * wth);
        }
        
        return area;
    }
};