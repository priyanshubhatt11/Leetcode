class Solution {
public:
    // "101101"
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& q) {
        map<long long, pair<int,int>> mp;
        int mm = INT_MIN;
        for(int i=0;i<q.size();i++){
            mm = max(mm, q[i][0] ^ q[i][1]);
        }
        bool flag = false;
        for(int i=0;i<s.size();i++){
            
            long long c=0;
            if(flag == false && s[i] == '0'){
                mp[c] = {i, i};
                flag = true;
            }
            if(s[i] == '1'){
                for(int j=i;j<s.size();j++){
                    c = c*2 + s[j]-'0';
                    if(c > mm)break;
                    if(!mp.count(c)){
                        mp[c] = {i,j};
                    }
                    
                    //cout<<c<<" ";
                }
            }
        }
        
        vector<vector<int>> ans(q.size());
        for(int i=0;i<q.size();i++){
            int x = q[i][0] ^ q[i][1];
            if(!mp.count(x)){
                ans[i].push_back(-1);
                ans[i].push_back(-1);
            }
            else{
                ans[i].push_back(mp[x].first);
                ans[i].push_back(mp[x].second);
            }
        }
        return ans;
   
    }
};