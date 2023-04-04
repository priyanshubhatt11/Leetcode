class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> set;
        
        int ans =0;
        for(auto i: s){
            if(set.find(i) != set.end()){
                ans++;
                set.clear();
                set.insert(i);
            }
            else{
                set.insert(i);
            }
        }
        return ans+1;
    }
};