class OrderedStream {
public:
    map<int, string> mp;
    int m , n=1;
    OrderedStream(int x) {
        m=x;
    }
    
    vector<string> insert(int key, string value) {
        mp[key] = value;
        vector<string> ans;
        for(int i=key;i<=m;i++){
            if(i == n && mp[i] != ""){
                ans.push_back(mp[i]);
                n++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};

