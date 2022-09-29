class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        for(int i = 0; i < n; i++){
                min_heap.push({abs(arr[i] - x ), i});    
        }
        while(!min_heap.empty()  && k > 0){
            ans.push_back(arr[min_heap.top().second]);
            min_heap.pop();
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};