class Solution {
public:
    int ladderLength(string beg, string end, vector<string>& words) {
        //unordered_map<string ,int> mp;
        unordered_set<string> st(words.begin(), words.end());
        //for(auto i:words)mp[i]++;
        
        queue<pair<string,int>> q;
        q.push({beg, 0});
        
        while(!q.empty()){
            string s = q.front().first;
            int c = q.front().second;
            q.pop();
            if(s == end)return c+1;
            for(int i=0;i<s.size();i++){
                char original = s[i];
                for(char j='a';j<='z';j++){
                    //string temp = s.substr(0,i) + j + s.substr(i+1);  // or
                    s[i] = j;
                    if(st.find(s) != st.end()){
                        //cout<<temp<<" ";
                        st.erase(s);
                        q.push({s, c+1});     
                    }
                }
                s[i] = original;
            }
        }
        return 0;
    }
};