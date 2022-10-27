class Solution {

#define ll long long
    
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        
        ll bad = 0;
        ll dip = 0;
        ll need = 0;
        
        for (auto v : transactions) {
            if (v[0] <= v[1]) {
                need = max(need, (ll)v[0]);
            }
            else {
                bad += (v[0] - v[1]);
                dip = max(dip, (ll)v[1]);
            }
        }
        
        return bad + max(dip, need);
        
    }
};