class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int sum = 0, maxi = INT_MIN;
        
        unordered_map<char,int> m;
        for(int i=0;i<chars.size();i++) m[chars[i]]=i;
        
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])==m.end()) sum += (s[i]-'a'+1);
            else
            {
                int index = m[s[i]];
                sum += vals[index];
            }
            
            maxi = max(maxi,sum);
            if(sum<0) sum=0;
        }
        if(maxi<0) return 0;
        return maxi;
    }
};