//  https://www.youtube.com/watch?v=csH0hKEgTSY

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& t) {
        long long total =0;
        int mi =0;
        
        for(auto &i: t){
            mi = max(mi , min(i[0] , i[1]));
            total += max(0, i[0] - i[1]);
        }
        
        return total + mi;
    }
};