class MapSum {
public:
   // int ans =0;
    unordered_map<string,int> map;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        map[key] = val;
    }
    
    int sum(string prefix) {
        int ans= 0;
        int n = prefix.size();
        for(auto i:map){
            string ss = i.first;
            string nn = ss.substr(0, n);
            if(nn == prefix){
                ans += i.second;
            }
        }
        return ans;
    }
};
