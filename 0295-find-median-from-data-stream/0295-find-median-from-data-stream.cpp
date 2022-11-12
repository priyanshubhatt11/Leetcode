class MedianFinder {
public:
    
    //  2 4 4    |    8 9 9
    //  max-heap      min-heap   ->  top();
    
    priority_queue<int> maxpq;
    priority_queue<int, vector<int> , greater<int>> minpq;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxpq.empty() || maxpq.top() > num){
            maxpq.push(num);
        }
        else{
            minpq.push(num);
        }
        
        if(maxpq.size()+2 == minpq.size()){     // maximum diifernce should be only 1
            int x = minpq.top();
            minpq.pop();
            maxpq.push(x);
        }
        else if(minpq.size()+2 == maxpq.size()){
            int x = maxpq.top();
            maxpq.pop();
            minpq.push(x);
        }
    }
    
    double findMedian() {
        if(maxpq.size() == minpq.size()){
            return (maxpq.top() + minpq.top())/2.0;
        }   
        if(maxpq.size() > minpq.size()){
            return maxpq.top();
        }
        return minpq.top();
    }
};


















