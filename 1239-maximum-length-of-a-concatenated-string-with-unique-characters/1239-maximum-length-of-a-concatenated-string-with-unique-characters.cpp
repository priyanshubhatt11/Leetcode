class Solution {
public:
    int ans =0;
    
    void solve(vector<string>&arr, vector<bool> &vis, int idx, int sum){
        if(idx >= arr.size()){
            ans = max(ans, sum);
            return;
        }
        
        bool flag = false;
        vector<bool> temp = vis;
        for(char i: arr[idx]){
            if(temp[i-'a'] == true){
                flag = true;
                break;
            }
            temp[i-'a'] = true;
        }
        if(!flag){  // add sum
            //cout<<arr[idx]<<" ";
            solve(arr, temp, idx+1, sum + arr[idx].size());
        }
        solve(arr, vis, idx+1, sum);        
    }
    
    int maxLength(vector<string>& arr) {
        vector<bool> vis(26, false);
        solve(arr, vis, 0, 0);
        return ans;
    }
};