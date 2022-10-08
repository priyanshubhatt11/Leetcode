class OrderedStream {
public:
    
    vector<string> vec;
    int i=0;
    int nn ;
    
    OrderedStream(int n) {
        vec = vector<string>(n, "");
        nn = n;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> ans;
        vec[idKey-1] = value;
        while(i<nn && vec[i] != ""){
            ans.push_back(vec[i]);
            i++;
        }
        return ans;
    }
};

