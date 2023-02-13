class Solution {
public:
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    
    void dfs(string beg, string s, vector<string>&vec){
        if(s == beg){
            ans.push_back(vec);
            return;
        }
        
        int c = mp[s];
        for(int i=0;i<s.size();i++){
            char orig = s[i];
            for(char j='a';j<='z';j++){
                s[i] = j;
                if(mp.find(s) != mp.end() && mp[s]+1 == c){
                    vec.push_back(s);
                    dfs(beg, s, vec);
                    vec.pop_back();
                }
            }
            s[i] = orig;
        }
    }
    
    vector<vector<string>> findLadders(string beg, string en, vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        st.erase(beg);
        mp[beg] = 1;
        queue<string> q;
        q.push(beg);
        while(!q.empty()){
            string s = q.front();
            q.pop();
            for(int i=0;i<s.size();i++){
                char orig = s[i];
                int c = mp[s];
                for(char j='a';j<='z';j++){
                    s[i] = j;
                    if(st.count(s)){
                        st.erase(s);
                        q.push(s);
                        mp[s] = c+1;
                    }
                }
                s[i] = orig;
            }
        }
        //for(auto i:mp)cout<<i.first<<" "<<i.second<<endl;
        vector<string> vec;
        vec.push_back(en);
        
        if(mp.find(en) != mp.end()){
            dfs(beg, en,  vec);
        }
        for(auto &i:ans)reverse(i.begin(), i.end());
        return ans;
    }
};