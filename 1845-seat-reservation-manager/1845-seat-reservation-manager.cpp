class SeatManager {
public:
    set<int> set;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            set.insert(i);
        }
    }
    
    int reserve() {
        int res = *begin(set);
        set.erase(res); 
        return res;
    }
    
    void unreserve(int seatNum) {
        set.insert(seatNum);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */