class Solution {
public:
    
    int solve(string s, int i, int j){
        while(i>=0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
        }

        return j-i-1;
    }
    
    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        int start = 0, end =0;
        int len =0;
        for(int i=0;i<s.size();i++){
          
            int odd = solve(s, i, i);
            int even = solve(s, i, i+1);
            
            if(len < max(odd, even)){
                //cout<<"a";
                len = max(odd, even);
                start = i - (len-1)/2;
                //end = i + (len)/2;
            }
                                    
        }
        return s.substr(start, len);
    }
};