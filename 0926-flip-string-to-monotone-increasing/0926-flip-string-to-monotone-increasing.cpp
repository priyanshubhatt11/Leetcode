class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int c=0,f=0;
        for(auto i:s){
            if(i == '1')c++;
            else f++;
            
            f = min(f,c);
        }
        return f;
    }
};