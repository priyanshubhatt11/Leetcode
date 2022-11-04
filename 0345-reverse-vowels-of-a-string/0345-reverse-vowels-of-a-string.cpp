class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vec;
        for(auto i:s){
            if(i == 'a' || i=='e' || i=='i' || i== 'o' || i == 'u' || i=='A' || i=='E' || i=='I' || i=='O' || i=='U'){
                vec.push_back(i);
            }
        }
        int idx =0;
        reverse(vec.begin(), vec.end());
        for(int i=0;i<s.size();i++){
             if(s[i] == 'a' || s[i]=='e' || s[i]=='i' || s[i]== 'o' || s[i] == 'u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                 s[i] = vec[idx];
                 idx++;
             }
        }
        return s;
        
    }
};