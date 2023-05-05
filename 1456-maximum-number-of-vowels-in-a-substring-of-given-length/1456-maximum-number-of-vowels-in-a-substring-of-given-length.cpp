class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> st;
        st.insert('a');st.insert('e');st.insert('i');st.insert('o');st.insert('u');
        int ans =0;
        int c =0;
        for(int i=0;i<s.size();i++){
            if(i>=k){
                if(st.count(s[i-k]))c--;
            }
            if(st.count(s[i]))c++;
            ans = max(ans, c);
            
        }
        return ans;
    }
};