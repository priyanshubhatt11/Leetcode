class Encrypter {
public:
    
    unordered_map<char, string> map;
    unordered_map<string, int> decryptCount;    // count number of string
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dict) {
        for(int i=0;i<keys.size();i++){
            map[keys[i]] = values[i];
        }
        
        // encrypt strings of dictionary and store in map and then return the count of asked string
        for(auto i: dict){
            string str = this->encrypt(i);
            decryptCount[str]++;
        }
    }
    
    string encrypt(string word1) {
        string s = "";
        for(auto i: word1){
            if(!map.count(i))return "";
            s += map[i];
        }
        return s;
    }
    
    int decrypt(string word2) {
        return decryptCount[word2];
    }
};
