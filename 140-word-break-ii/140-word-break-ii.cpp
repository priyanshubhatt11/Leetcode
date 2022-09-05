class Solution {
public:
    unordered_map<string,int> map;
    
    void solve(string s, vector<string> wD, vector<string> &ans, string str, int idx){
        //cout<<str<<" | ";
        if(idx == s.size()){
            cout<<"done";
            ans.push_back(str);
            return;
        }
        
        for(int i = idx+1;i<=s.size();i++){
            //cout<<idx <<"-"<<i<<" ";
            string curr = s.substr(idx, i-idx);     // (0 , 1-0)
            string temp = str;
            //cout<<str<<" 1 ";
            if(map[curr] == true){
                if(temp == "") temp = curr;
                else    temp = temp + " "+curr;
                solve(s, wD, ans, temp , i);
            }
            //cout<<curr<<" ";
        }
        
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wD) {
        for(auto i:wD){
            map[i]++;
        }
        vector<string> ans;
        solve(s, wD, ans, "", 0);
        return ans;
    }
};