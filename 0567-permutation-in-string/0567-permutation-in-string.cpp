class Solution {
public:
    
    bool check(vector<int> &vec){
        for(auto i:vec){
            if(i != 0)return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for(auto i:s1)freq[i-'a']++;
        for(int i=0;i<s2.size();i++){
            vector<int> temp = freq;
            for(int j=i;j<s2.size();j++){
                int x = s2[j]-'a';
                if(temp[x] > 0){
                    temp[x]--;
                }
                else break;
                if(check(temp))return true;
            }
        }
        return false;
    }
};