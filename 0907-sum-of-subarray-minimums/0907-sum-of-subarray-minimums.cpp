class Solution {
public:
    
    void leftfill(vector<int>&arr, vector<int>&left){
        stack<int> st;
        st.push(-1);
        for(int i=0;i<arr.size();i++){
            while(st.top() != -1 && arr[st.top()] > arr[i])   st.pop();
            
            left[i] = st.top();
            st.push(i);
        }
    }
    
    void rightfill(vector<int>&arr, vector<int>&right){
        int n = arr.size();
        stack<int> st;
        st.push(n);
        for(int i=n-1;i>=0;i--){
            while(st.top() != n && arr[st.top()] >= arr[i])  st.pop();
            
            right[i] = st.top();
            st.push(i);
        }
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int const mod = 1e9+7;
        int n = arr.size();
        vector<int> left(n), right(n);
        
        leftfill(arr,left);
        rightfill(arr, right);
        
        // for(int i:left)cout<<i<<" ";
        // cout<<endl;
        // for(int i:right)cout<<i<<" ";
        
        long long ans=0;
        for(int i=0;i<n;i++){
            long long x = (((long long)(i-left[i]) * (right[i] - i)%mod) * arr[i])%mod;
            ans = (ans%mod + x%mod)%mod;
        }
        return ans;
        
        
    }
};








