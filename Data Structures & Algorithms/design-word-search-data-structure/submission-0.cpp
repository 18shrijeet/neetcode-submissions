class Node{
public:
    Node* links[26];
    bool isEnd;

    Node(){
        for(int i=0;i<26;i++){
            links[i] = nullptr;
        }
        isEnd = false;
    }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for(char c: word){
            int i = c - 'a';
            if(!cur->links[i]) cur->links[i] = new Node();
            cur = cur->links[i];
        }
        cur->isEnd = true;
    } 

    bool search(string word) {
        return dfs(word , 0, root);
    }
    
    bool dfs(string& word, int index, Node* cur) {
        if(index == word.size()) {
            return cur->isEnd;
        }
        char c = word[index];
        if(c != '.') {
            int i = c - 'a';

            if(!cur->links[i]) return false;

            return dfs(word, index + 1, cur->links[i]);
        }
        for(int i = 0; i < 26; i++) {
            if(cur->links[i]) {
                if(dfs(word, index + 1, cur->links[i])) {
                    return true;
                }
            }
        }
        return false;
        }
};
