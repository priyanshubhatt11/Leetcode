
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            Node* prev = NULL;
            while(k--){
                Node*temp = q.front();
                q.pop();
                
                temp->next = prev;
                prev = temp;
                
                if(temp->right){
                    q.push(temp->right);
                }
                if(temp->left){
                    q.push(temp->left);
                }
            }
        }
        return root;
        
    }
};