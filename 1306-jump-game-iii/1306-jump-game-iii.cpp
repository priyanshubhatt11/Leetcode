class Solution {
public:
    
    bool solve(vector<int>&arr, int idx, vector<bool> &vis){
        //cout<<idx<<" ";
        if(idx <0 || idx>=arr.size() || vis[idx] )return false;
        
        if(arr[idx] == 0)return true;
        vis[idx] = true;
        return solve(arr, idx - arr[idx], vis) || solve(arr, idx + arr[idx], vis);
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        
        return solve(arr, start, vis);
    }
};