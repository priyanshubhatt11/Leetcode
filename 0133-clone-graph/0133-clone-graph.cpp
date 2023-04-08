/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> copies;
    
    Node* cloneGraph(Node* node) {
        
        // IMPORTANT TO USE MAP FOR CREATING COPIES OF NEIGHBOURS AND STORING THEM ONE BY ONE IN ITERATION AND NOT ONCE ALL.
        // WE WILL ITERATE ORIGINAL GRAPH USING BFS AND WILL IMPLEMENT THESE MODIFICATIONS TO CREATE A NEW GRAPH PARALLELY.
        
        if(node==NULL) return NULL;
        Node* head = new Node(1, {});
        copies[node] = head;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            for(auto x : temp->neighbors)
            {
                if(copies.find(x) == copies.end())
                {
                    copies[x] = new Node(x->val, {});
                    q.push(x);
                }
                copies[temp]->neighbors.push_back(copies[x]);
            }
        }
        return head;
    }
};




