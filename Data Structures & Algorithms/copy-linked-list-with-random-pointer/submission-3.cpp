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
        mp[nullptr]= nullptr; // Needed for the nullptr if handling to avoid creating new Node 
        // else do this
        //mp[t]->next = t->next ? mp[t->next] : nullptr;
        // mp[t]->random = t->random ? mp[t->random] : nullptr;
        Node* t = head;
        while(t){
            if(mp.find(t) == mp.end()){
                mp[t] = new Node(0);
            }
            mp[t]->val = t->val;

            if(mp.find(t->next) == mp.end()){
                mp[t->next] = new Node(0);
            }
            mp[t]->next = mp[t->next];

            if(mp.find(t->random) == mp.end()){
                mp[t->random] = new Node(0);
            }
            mp[t]->random = mp[t->random];
            t= t->next;
        }
        return mp[head];
    }
};
