class LUPrefix {
public:
    
    set<int> set;
    int i=0;
    LUPrefix(int n) {
        
    }
    
    void upload(int video) {
        set.insert(video);
    }
    
    int longest() {
        while(set.count(i+1)){
            i++;
        }
        return i;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */