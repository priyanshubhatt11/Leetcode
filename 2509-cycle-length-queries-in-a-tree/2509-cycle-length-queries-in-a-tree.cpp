class Solution {
public:
    // 2*val , 2*val+1
    
    // find Longest Common Ancestor
    int solve(int x, int y){
        int c=0;
        while(x!=y){
            if(x>y) x/=2;
            else y/=2;
            c++;
        }        
        return c;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) {
        vector<int> ans;
        
        for(auto i:q){
            int x = solve(i[0], i[1]);
            ans.push_back(x+1);
        }
        return ans;
    }
};