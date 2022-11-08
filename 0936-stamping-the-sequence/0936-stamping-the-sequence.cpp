//  https://www.youtube.com/watch?v=EtalsGoNrBI

class Solution {
public:
    
    bool canReplace(string &s, string &tar, int idx){
       
        for(int i=0;i<s.size();i++){
            if(tar[i+idx] != s[i] && tar[i+idx] != '?'){
                return false;
            }
        }
        return true;
    }
    void replace(string &tar, int idx, int n, int &count){
        
        for(int i=0;i<n;i++){
            if(tar[i+idx] != '?'){
                tar[i+idx] = '?';
                count++;
            }
        }
        
    }
    
    vector<int> movesToStamp(string s, string tar) {
        vector<bool> vis(tar.size()+1, false);
        int count=0;
        vector<int> vec;
        bool flag = false;
        while(count != tar.size()){
            flag = false;
            for(int i=0;i<=tar.size()-s.size();i++){
                //cout<<count<<" ";
                if(!vis[i] && canReplace(s, tar, i)){   // replace char of target to '?'
                    vis[i] = true;
                    vec.push_back(i);
                    replace(tar, i, s.size(), count);
                    flag = true;
                }
            }
            if(flag == false)return {};
            
        }
        
        reverse(vec.begin(), vec.end());
        return vec;
        
    }
};