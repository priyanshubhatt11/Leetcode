class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "",s2= "";
        for(string i: word1){
            for(char j: i){
                s1.push_back(j);
            }
        }
        for(string i: word2){
            for(char j: i){
                s2.push_back(j);
            }
        }
        return s1 == s2;
        
    }
};