class Solution {
public:
    //[4,1,5,2,6,2], k = 2 here 4, 5, 6 and 1, 2, 2 will form a group
    
    int LIS(vector<int> &vec){
        
        vector<int> temp;
        temp.push_back(vec[0]);
        for(int i=1;i<vec.size();i++){
            if(vec[i] >= temp.back()){
                temp.push_back(vec[i]);
            }
            else{
                int idx = upper_bound(temp.begin(), temp.end(), vec[i]) - temp.begin();
                temp[idx] = vec[i];          
            }
        }
        return temp.size();
        
        
    }
    
    int kIncreasing(vector<int>& arr, int k) {
        int ans =0;
        for(int i=0;i<k;i++){
            vector<int> vec;
            for(int j=i;j<arr.size();j+=k){
                vec.push_back(arr[j]);
                //cout<<"f ";
            }
           // cout<<endl;
            
            ans += vec.size() - LIS(vec);
        }
        return ans;
    }
};