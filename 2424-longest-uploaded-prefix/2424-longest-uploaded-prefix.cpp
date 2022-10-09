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
        //cout<<"x"<<endl;
        while(set.count(i+1)){
            //cout<<i<<" ";
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