class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rec) {
        long long ans=0;
        unordered_map<double ,int> map;
        for(auto i:rec){
            double nn = (double)i[0]/i[1];
            ans += map[nn];
            map[nn]++;
        }
        return ans;
    }
};