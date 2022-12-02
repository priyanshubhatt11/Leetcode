class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char> s1 , s2;
        vector<int> vec1(26,0), vec2(26,0);
        
        for(auto i:word1){
            s1.insert(i);
            vec1[i-'a']++;
        }
        for(auto i:word2){
            s2.insert(i);
            vec2[i-'a']++;
        }
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        return s1 == s2 && vec1 == vec2;
        
    }
};