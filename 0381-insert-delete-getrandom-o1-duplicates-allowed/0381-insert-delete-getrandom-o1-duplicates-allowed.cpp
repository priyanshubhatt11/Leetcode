class RandomizedCollection {
public:
    
    unordered_map<int, set<int>> mp;
    vector<int> vec;
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        vec.push_back(val);
        mp[val].insert(vec.size()-1);
        if(mp[val].size() == 1) return true;
        return false;
    }
    
    bool remove(int val) {
        
        if(mp.find(val) == mp.end())return false;
        // for(auto i:vec)cout<<i<<" ";
        // cout<<val;
        auto st = mp[val];
        int idx = *st.rbegin();
        int temp = vec.back();
        auto st2 = mp[temp];
        int idx2 = *st2.rbegin();
            mp[val].erase(*st.rbegin());
            

            vec[idx] = temp;
            
            mp[val].erase(idx);
            mp[temp].insert(idx);
            mp[temp].erase(idx2);
            
        
        

        vec.pop_back();
        if(mp[val].size() == 0){
            mp.erase(val);
        }
        
        return true;
    }
    
    int getRandom() {
        int x = vec.size();
        int n = rand()%x;
        return vec[n];
    }
};
