class NumArray {
public:
    vector<int> vec;
    int sum =0;
    
    NumArray(vector<int>& nums) {
        vec = nums;
        for(int i:nums) sum += i;
    }
    
    void update(int index, int val) {
        sum -= vec[index];
        sum += val;
        vec[index] = val;
    }
    
    int sumRange(int left, int right) {
        int ss = sum;
        for(int i=0;i<left;i++){
            ss -= vec[i];
        }
        for(int i=right+1;i<vec.size();i++){
            ss -= vec[i];
        }
        return ss;
    }
};

