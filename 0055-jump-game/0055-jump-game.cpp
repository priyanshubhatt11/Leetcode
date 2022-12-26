class Solution {
public:
    bool canJump(vector<int> &v) {
        int n = v.size();
        if(n == 1) return true;
        vector<bool> ans(n, false);
        ans.back() = true;
        int mn = n-1;
        for(int i = n-2; i >= 0; i--){
            if(i + v[i] >= mn){
                ans[i] = true;
                mn = i;
            }
        }
        return ans.front();
    }
};