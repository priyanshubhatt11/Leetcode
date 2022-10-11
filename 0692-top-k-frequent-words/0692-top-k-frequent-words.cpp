class Solution {
public:
    // can also be done by trie
    
    static bool compare(pair<int, string> &A, pair<int,string> &B){
        if(A.first != B.first)  return A.first > B.first;
        return A.second < B.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        
        for(auto i:words){
            map[i]++;
        }
        vector<pair<int , string>> arr;
        for(auto i: map){
            arr.push_back({i.second, i.first});
        }
        sort(arr.begin(), arr.end(), compare);
        
        vector<string> ans;
        for(int i=0;i<arr.size();i++){
            if(k == 0)return ans;
            ans.push_back(arr[i].second);
            k--;
        }
        return ans;
        
        
    }
};









