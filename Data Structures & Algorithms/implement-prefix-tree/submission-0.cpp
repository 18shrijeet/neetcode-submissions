class Node{
public:
    Node* links[26];
    bool isEnd;
    Node(){
        isEnd = false;
        for(int i = 0;i<26;i++){
            links[i] = nullptr;
        }
    }
};

class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char c: word){
            int index = c - 'a';
            if(!node->links[index]){
                node->links[index] = new Node();
            }
            node = node->links[index];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(char c: word){
            int index = c - 'a';
            if(!node->links[index]) return false;

            node= node->links[index];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch: prefix){
            int index = ch - 'a';
            if(!node->links[index]) return false;
            node = node->links[index];
        }
        return true;
    }
};
