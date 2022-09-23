class Solution {
public:
    char findTheDifference(string s, string t) {
        string a = s+t;
        char c =0;
        for(char i: a){
            c ^= i;
        }
        return c;
    }
};