class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        map<int,int> win, loss;
        
        for(auto i: m){
            win[i[0]]++;
            loss[i[1]]++;
        }
        
        vector<vector<int>> ans(2);
        
        for(auto i:win){
            int x = i.first;
            if(loss.find(x) == loss.end()){
                ans[0].push_back(x);
            }
        }
        for(auto i:loss){
            if(i.second == 1){
                ans[1].push_back(i.first);
            }
        }
        return ans;
        
    }
};