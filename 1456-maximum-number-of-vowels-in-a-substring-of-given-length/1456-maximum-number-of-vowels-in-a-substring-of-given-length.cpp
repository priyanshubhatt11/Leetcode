class Solution {
public:
    int maxVowels(string s, int k) {
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a'||s[i] =='e' || s[i] =='i' || s[i] == 'o' || s[i] == 'u'){
                s[i] = '1';
            }
            else{
                s[i] = '0';
            }
        }
        // for(auto i:s){
        //     cout<<i<<" ";
        // }
        int ans=0, c=0;
        for(int i=0;i<s.size();i++){
            int j = i-k;
            if(s[i] == '1')c++;
            if(j>=0){
                if(s[j] == '1')c--;
            }
            ans = max(ans, c );
        }
        return ans;
    }
};