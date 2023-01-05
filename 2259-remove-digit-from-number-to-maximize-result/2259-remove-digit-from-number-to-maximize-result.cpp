class Solution {
public:
    string removeDigit(string num, char digit) {
        vector<string> vec;
        for(int i=0;i<num.size();i++){
            if(num[i] == digit){
                string s = num.substr(0,i) + num.substr(i+1);
                vec.push_back(s);
            }
        }
        sort(vec.begin(), vec.end());
        return vec[vec.size()-1];
        
    }
};