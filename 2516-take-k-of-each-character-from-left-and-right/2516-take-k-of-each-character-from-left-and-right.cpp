class Solution {
public:
    
    // [_______________] - [_____------_____] = [[____]  +  [____]]
    
    int takeCharacters(string s, int k) {
        map<char, int> map;
        int n = s.size();
        for(auto i:s)map[i]++;
        if(map['a']<k || map['b']<k || map['c']<k)return -1;
        int i=0, j=0;
        int x = INT_MIN;
        
        while(i<n){
            map[s[i]]--;
            while(map['a'] < k || map['b'] < k || map['c'] < k){
                map[s[j]]++;
                j++;
            }
            x = max(x , i-j+1);
            i++;
        }
        return n- x;
        
    }
};












