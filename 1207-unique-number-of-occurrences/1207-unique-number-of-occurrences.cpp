class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i:arr){
            map[i]++;
        }
        unordered_set<int> set;
        for(auto i:map){
            set.insert(i.second);
        }
        
        return set.size() == map.size();
    }
};