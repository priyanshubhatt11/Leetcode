class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        
        for(int i:arr){
            map[i]++;
        }
        vector<pair<int,int>> vec;
        for(auto i: map){
            vec.push_back({i.second, i.first});     // {frequency, number}
        }
        
        sort(vec.begin(), vec.end());
        
        int i =0;
        while(k!=0){
            if(k - vec[i].first  < 0){
                break;
            }
            k = k- vec[i].first;
            i++;
        }
        return vec.size() - i;
    }
};