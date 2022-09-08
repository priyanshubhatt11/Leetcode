class Solution {
public:
    
    void solve(int k, int n, vector<vector<int>> &ans, vector<int>&vec,int idx){
        if(k <=0){
            if(n == 0){
                ans.push_back(vec);
            }
            return;
        }
        for(int i=idx ;i<=9;i++){
            vec.push_back(i);
            solve(k-1, n-i, ans, vec, i+1);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vec;
        solve(k,n, ans, vec, 1);
        return ans;
    }
};