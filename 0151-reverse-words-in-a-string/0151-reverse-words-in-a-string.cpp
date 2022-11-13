class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        
        int i=0;
        while(s[i] == ' '){
            i++;
        }
        string ss = s.substr(i);
        s = ss;
        int n = s.size()-1;
        string temp = "";
        for(int i=n;i>=0;i--){
            if(s[i] == ' ' && temp.size() == 0)continue;
            
            if(s[i] == ' '){
                reverse(temp.begin(), temp.end());
                ans += temp + " ";
                temp = "";
                //i--;
            }
            else{
                temp.push_back(s[i]);
            }
            
        }
        
        reverse(temp.begin(), temp.end());
        ans += temp;
        
        
        return ans;
    }
};