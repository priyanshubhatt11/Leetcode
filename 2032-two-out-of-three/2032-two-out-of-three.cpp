//Largest Rectangle in Histogram

class Solution {
public:
    
    void previousSmaller(vector<int>&mat, vector<int> &ps){
        stack<int> st;
        st.push(-1);
        for(int i=0;i<mat.size();i++){
            int x = mat[i];
            while(st.top() != -1 && mat[st.top()] >= x){
                st.pop();
            }
            
            ps[i] = st.top();
            st.push(i);
        }
    }
    
    void nextSmaller(vector<int> &mat, vector<int>&ns){
        stack<int> st;
        int n = mat.size();
        st.push(n);
        for(int i=n-1;i>=0;i--){
            int x = mat[i];
            while(st.top() != n && mat[st.top()] >= x){
                st.pop();
            }
            ns[i] = st.top();
            st.push(i);
        }
    }
    
    int largestRec(vector<int> mat, int n){
        
        vector<int> ps(n);
        previousSmaller(mat, ps);
        
        vector<int> ns(n);
        nextSmaller(mat, ns);
        
        // for(auto i:ps){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i:ns){
        //     cout<<i<<" ";
        // }
        int area =0;
        for(int i=0;i<mat.size();i++){
            int wth = ns[i] - ps[i] - 1;
            area = max(area , mat[i]* wth);
        }
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        // vector<char> nn = {'1','6','4','2', '5'};
        // int m = nn.size();
        
        
        int n = mat[0].size();
        vector<int> vec(n, 0);
        int area = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == '1'){
                    vec[j]++;
                }
                else{
                    vec[j] =0;
                }
            }
            
            // for(int k=0;k<n;k++){
            //     cout<<vec[k]<<" ";
            // }
            // cout<<endl;
            area = max(area, largestRec(vec, n));
            
            //cout<<area<<" ";
        }
        return area;
    }
};