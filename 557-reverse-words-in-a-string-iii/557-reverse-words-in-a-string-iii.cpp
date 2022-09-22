class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        stringstream nn(s);
        string t="";
        while(getline(nn , t, ' ')){
            reverse(t.begin(),t.end());
            ans+= t+" ";
        }
        ans.pop_back();
        return ans;
    }
};
