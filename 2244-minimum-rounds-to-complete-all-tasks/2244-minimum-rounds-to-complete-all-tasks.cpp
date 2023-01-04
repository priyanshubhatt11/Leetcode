class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> map;
        for(auto i:tasks)map[i]++;
        int ans =0;
        for(auto i:map){
            if(i.second == 1)return -1;
            
            ans += i.second/3;
            if(i.second%3){
                ans++;
            }
        }
        return ans;
    }
};