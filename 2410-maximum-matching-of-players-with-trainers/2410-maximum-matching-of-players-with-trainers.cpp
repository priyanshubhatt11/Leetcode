class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        // 2 4
        // 3 4 4
        int ans =0, j=0;
        for(int i=0;i<t.size() && j<p.size();i++){
            if(t[i] >= p[j]){
                ans++;
                j++;
            }
        }
        return ans;
    }
};