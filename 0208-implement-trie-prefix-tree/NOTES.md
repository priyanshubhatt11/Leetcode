if(pre.length() == 0){
return true;
}
TrieNode *temp;
int idx = pre[0] - 'a';
if(root->child[idx] != NULL){
temp = root->child[idx];
}
else{
return false;
}
return startsWithUtil(temp , pre.substr(1));
}
bool startsWith(string prefix) {
return startsWithUtil(root, prefix);
}
/*************************************/
};
​
​
/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/