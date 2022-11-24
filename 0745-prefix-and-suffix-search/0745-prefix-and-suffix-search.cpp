class WordFilter {
public:
    // a|e  a|le a|ple a|pple a|apple ap|e app|e app|le ...
    unordered_map<string, int> map;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string s = words[i];
            for(int j=1;j<=s.size();j++){
                string s1 = s.substr(0,j);
                for(int k=s.size()-1;k>=0;k--){
                    string s2 = s.substr(k);
                    //cout<<s1<<" | "<<s2<<endl;
                    map[s1 + "|" + s2] = i+1;
                }
            }           
        }
    }
    
    int f(string pref, string suff) {
        return map[pref +"|" + suff] - 1; // -1 so that if string not found in map 
    }
};

