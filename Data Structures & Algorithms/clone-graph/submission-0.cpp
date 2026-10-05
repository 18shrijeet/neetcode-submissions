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
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        unordered_map<Node*, Node*>oldtoNew; // mapping oldNode->newNode and we populate neighbors of these
        queue<Node*>q;
        oldtoNew[node] = new Node(node->val);
        q.push(node);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            for(Node* nei: cur->neighbors){
                if(oldtoNew.find(nei) == oldtoNew.end()){
                    oldtoNew[nei] = new Node(nei->val);
                    q.push(nei);
                }
                oldtoNew[cur]->neighbors.push_back(oldtoNew[nei]);
            }
        }
        return oldtoNew[node];
        }
};
