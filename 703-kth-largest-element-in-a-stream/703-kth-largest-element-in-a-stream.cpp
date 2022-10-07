class KthLargest {
public:
    
    priority_queue<int, vector<int> , greater<int>> q;     // min heap
    int k;
    KthLargest(int K, vector<int>& nums) {
        k=K;
        for(int i:nums){
            q.push(i);
            if(q.size() > k){
                q.pop();
            }
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > k){
            q.pop();
        }
        return q.top();
    }
};

