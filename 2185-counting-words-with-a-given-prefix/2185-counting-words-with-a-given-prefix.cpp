class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int n=words.size();
        int m=words[0].size();
        int x=0;
        for(int i=0;i<n;i++)
        {
            int c =0;
            for(int j=0;j<pref.size();j++)
            {
                if(words[i].size() >= pref.size() && words[i][j]==pref[j])
                {
                    c++;
                }
            }
            if(c == pref.size()) x++;
        }
        return x;
    }
};