class Solution {
public:
    int par[301]; // make a global parent array of given max constraint size
    
    // using DSU
    
    // (find function) to find parent of a string
    int find(int a)
    {
        if(par[a] < 0) return a;
        
        return par[a] = find(par[a]); // path compression
    }
    
    // Union function to merge them
    void Union(int a, int b)
    {
        int p = find(a); // find parent of a
        int q = find(b); // find parent of b
        
        if(p == q) // if already they have the same parent, then simply
            return; // return
        
        // else make q as parent of p
        par[p] = q; // make any one as parent
        
    //  par[q] = p; you may also write like this
        
    }
    
    // function to compare whether two string are similiar or not
    bool areSimiliar(string &str1, string &str2)
    {
        // if both are already same, return true
        if(str1 == str2)
            return true;
        
        int count = 0; // variable to count at how many places they differ
        
        // traverse in string 1
        for(int i = 0; i < str1.size(); i++)
        {
            // if not equal, increment count
            if(str1[i] != str2[i])
            {
                count++;
            }
        }
        
        // if count == 2, means they exactly differ at two positions
        // so yes they are similiar, we can make them same by swapping
        if(count == 2) return true;
        
        // other than difference from two positions,
        // all other number of differences are not make string similiar,
    // even if they differ at only one position, that is also not similiar
        return false;  
    }
    
    int numSimilarGroups(vector<string>& arr) {
        int n = arr.size(); // how many strings are their
        
        // Intially all are alone, so make everyone as -1
        for(int i = 0; i < n; i++) par[i] = -1;
        
        // now for every pair of strings
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(areSimiliar(arr[i],arr[j])) // if they are similar
                {
                    Union(i, j); // merge them 
                }
            }
        }
        
        int ans = 0; // variable which store our answer
        
        // now at last, we are able to put all strings who are similiar
        // in a group, so finally just count how many groups are their
        for(int i = 0; i < n; i++)
        {
            // if par[i] is negative that means it is parent of some group
            // increment answer
            if(par[i] < 0) 
                ans++;
        }
        
        return ans; // finally return our answer
    }
};