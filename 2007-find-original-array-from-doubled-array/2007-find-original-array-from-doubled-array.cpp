class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ch) {
        sort(ch.begin(), ch.end());
        unordered_map<int,int> mp;
        vector<int> ans;
        if(ch.size() %2 == 1)return {};
        for(int i:ch){
            mp[i]++;
        }

        
        for(int i:ch){
            if(mp[i] == 0)continue;
            if(mp[i*2] == 0)return {};
            ans.push_back(i);
            mp[i]--;
            mp[i*2]--;
        }
        return ans;
        
    }
};