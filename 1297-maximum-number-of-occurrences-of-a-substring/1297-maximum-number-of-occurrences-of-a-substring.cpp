class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int result=0;
     
      result=max(fun(s,minSize,maxLetters),result);
        return result;
    }
    int fun(string &s, int ws,int k)
    {
        int i=0;
        int j=0;
        int result=0;
        unordered_map<string,int>mp;
        int count=0;
        vector<int>v(26,0);
        while(j-i+1<ws)
        {
            v[s[j]-'a']++;
            if(v[s[j]-'a']==1)
                count++;
            j++;
        }
        

        while(j<s.size())
        {
            v[s[j]-'a']++;
            if(v[s[j]-'a']==1)
                count++;
            if(count<=k)
                mp[s.substr(i,j-i+1)]++;
            v[s[i]-'a']--;
            if(v[s[i]-'a']==0)
                count--;
            i++;
            j++;
        }
        
      for(auto p:mp)
       result=max(p.second,result);
       
        return result;  
    }
};