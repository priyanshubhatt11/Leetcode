/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int n = q.size();
            vector<int> vec;
            
            for(int i=0;i<n;i++){
                Node *temp = q.front();
                q.pop();
                for(auto i : temp->children){
                    q.push(i);
                }
                vec.push_back(temp->val);
                
            }
            
            ans.push_back(vec);
        }
        return ans;
    }
};




















