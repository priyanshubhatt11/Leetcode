class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        string str = s;
        for(int i=1;i<s.size();i++){
            str = min(str , s.substr(i) + s.substr(0,i));
        }
        return str;
    }
};