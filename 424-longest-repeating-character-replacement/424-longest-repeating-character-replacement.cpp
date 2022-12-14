class Solution {
public:
    
    string s ;
  int solve( char ch, int k){
      int j=0,ans=0,c=0;
      for(int i=0;i<s.size();i++){
          if(s[i] != ch)c++;
          while(c >k){
              if(s[j] != ch)c--;
              j++;
          }
          ans = max(ans, i-j+1);
      }
      return ans;
      
  }
    
    int characterReplacement(string t, int k) {
        s = t;
        int ans=0;
        for(char i='A'; i<='Z';i++){
            ans = max(ans, solve(i, k));
        }
        return ans;
    }
};