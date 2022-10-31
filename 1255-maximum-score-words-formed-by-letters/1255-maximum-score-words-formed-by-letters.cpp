//https://www.youtube.com/watch?v=AoCrCsJLiSs
class Solution {
public:
    
    void solve(vector<string>& words, vector<int> &count, vector<int>&score, vector<int> &totalC, int &ans, int temp, int idx){
        if(idx == words.size()+1)return;
        
        for(int i=0;i<26;i++){
            if(totalC[i] > count[i])return;
        }
        
        ans = max(ans, temp);
        for(int i=idx;i<words.size();i++){
            for(char j: words[i]){
                temp += score[j-'a'];
                totalC[j -'a']++;
            }
            
            solve(words, count, score, totalC, ans , temp, i+1);
            
            for(char j:words[i]){
                temp -= score[j - 'a'];
                totalC[j-'a']--;
            }
        }
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0), totalC(26, 0);
        
        for(char i: letters){
            count[i-'a']++;
        }
        
        int ans =0;
        solve(words, count, score, totalC, ans, 0 , 0);
        return ans;
    }
};