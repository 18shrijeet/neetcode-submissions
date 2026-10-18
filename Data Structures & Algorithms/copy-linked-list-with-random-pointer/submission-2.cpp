/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        unordered_map<Node*, Node*>mp;
        Node* t = head;
        while(t){
            if(mp.find(t) == mp.end()){
                mp[t] = new Node(t->val);
            }
            t= t->next;
        }
        for(auto i: mp){
            if(i.first){
                i.second->next = mp[i.first->next];
                i.second->random = mp[i.first->random];
            }
        }
        return mp[head];
    }
};
