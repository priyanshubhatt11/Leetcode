class Solution {
public:

    int minDeletions(string s) {
        vector<int> vec(26,0);
        for(auto &i:s){
            vec[i-'a']++;
        }
        
        int ans =0;
//         unordered_map<int,int> mp;
        
//         for(int i=0;i<26;i++){
//             int x = vec[i];
//             if(x == 0)continue;            
//             if(mp.find(x) != mp.end()){
//                 while(x>0 && mp.find(x) != mp.end()){
//                     ans++;
//                     x--;
//                 }
//             }
//             mp[x]++;
            
//         }
//         return ans;
        
        
//           OR
        
        
        sort(vec.begin(), vec.end());
        
        for(int i=24;i>=0;i--){
            if(vec[i] == 0)break;
            
            if(vec[i] >= vec[i+1]){     // greater because [ '1' 0 1 4 ] for abbbbce
                int temp = vec[i];
                vec[i] = max(0, vec[i+1] - 1);
                ans += temp - vec[i];
            }
            
        }
        return ans;
        
        
        
    }
};














