class Solution {
public:
    bool halvesAreAlike(string s) {
        transform(s.begin(), s.end() , s.begin() , ::tolower);
        int n = s.size()/2;
        int c=0,z=0;
        for(int i=0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                c++;
            }
        }
        for(int i=n;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                z++;
            }
        }
        return c== z;
    }
};