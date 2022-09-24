class Solution {
public:
    int countConsistentStrings(string all, vector<string>& words) {
        int ans=0;
        vector<int> vec(words.size(),0);
        int match=0;
        for(char ch:all){
            match = match | (1<<(ch- 'a'));
        }
        
        for(int i=0;i<words.size();i++){
            bool flag = true;
            for(char ch: words[i]){
                if(!(match & (1<<(ch-'a')))){
                    flag = false;
                    break;
                }
            }
            if(flag)    ans++;
        }
        
        return ans;
    }
};