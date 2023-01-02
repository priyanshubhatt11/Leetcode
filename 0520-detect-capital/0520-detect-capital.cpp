class Solution {
public:
    bool detectCapitalUse(string word) {
        int x=0, f=0, y=0, n=word.size();
        for(int i=0;i<n;i++){
            if(word[i]>=65 && word[i]<=90){
                x++;
                if(i==0)f=1;
            }
            else y++;
        }
        if(y == n || x == n || (f == 1&& y == n-1))return true;
        return false;
    }
};