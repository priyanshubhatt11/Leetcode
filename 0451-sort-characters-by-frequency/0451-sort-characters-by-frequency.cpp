class Solution {
public:
    
    bool static comp(pair<char,int> &A, pair<char,int> &B){
        return A.second > B.second;
    }
    
    string frequencySort(string s) {
        vector<pair<char,int>> vec(256);
        for(char i:s){
            vec[i].first = i;   vec[i].second++;
        }
        sort(vec.begin(), vec.end(), comp);
        //for(auto i:vec)cout<<i.first<<" "<<i.second<<endl;
        string temp = "";
        for(auto i:vec){
            for(int j=0;j<i.second;j++){
                temp += i.first;
            }
        }
        return temp;
    }
};