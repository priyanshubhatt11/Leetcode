class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> map;
        int ans =0;
        for(auto i:tasks){
            map[i]++;
        }
        for(auto i:map){
            if(i.second == 1)return -1;
            
            else {
                ans+= (i.second+2)/3;
            }
        }
        return ans;
    }
};