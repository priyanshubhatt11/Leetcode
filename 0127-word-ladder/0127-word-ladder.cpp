class Solution {
public:
    int ladderLength(string beg, string end, vector<string>& words) {
        unordered_map<string ,int> mp;
        for(auto i:words)mp[i]++;
        
        queue<pair<string,int>> q;
        q.push({beg, 1});
        
        while(!q.empty()){
            string s = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<s.size();i++){
                for(char j='a';j<='z';j++){
                    string temp = s.substr(0,i) + j + s.substr(i+1);
                    if(mp[temp] > 0){
                        //cout<<temp<<" ";
                        mp[temp]--;
                        q.push({temp, c+1});
                        if(temp == end)return c+1;
                    }
                }
            }
        }
        return 0;
    }
};