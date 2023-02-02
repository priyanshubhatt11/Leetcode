class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<vector<int>, int> mp;
        for(auto i:pieces)mp[i]++;
        for(int i=0;i<arr.size();i++){
            vector<int> vec;
            bool flag = false;
            for(int j=i;j<arr.size();j++){
                vec.push_back(arr[j]);
                if(mp[vec] > 0){
                    flag = true;
                    i=j;
                    break;
                }
                
            }
            // for(auto i:vec)cout<<i<<" ";
            // cout<<endl;
            if(!flag)return false;
        }
        return true;
    }
};