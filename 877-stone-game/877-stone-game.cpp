class Solution {
public:
    
    int solve(vector<int>&pile, int i, int j){
        if(i>j)return 0;
        
        return max(pile[i] - solve(pile, i+1, j) , pile[j] - solve(pile, i, j-1));
    }
    
    bool stoneGame(vector<int>& p) {
        // int ans = solve(p, 0, p.size()-1);
        // cout<<ans;
        return 1;
    }
};