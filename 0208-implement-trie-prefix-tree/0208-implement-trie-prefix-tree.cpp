class Node{
public:
    Node* children[26];
    bool eow;
    Node() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        eow = false;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node*temp = root;
        for(char c: word) {
            int idx = c-'a';
            if(temp->children[idx] == nullptr) {
                temp->children[idx] = new Node();
            }
            temp = temp->children[idx];
        }
        temp->eow = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(char c: word) {
            int idx = c - 'a';
            if(temp->children[idx] == nullptr) return false;
            temp = temp->children[idx];
        }
        return temp->eow;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char c: prefix) {
            int idx = c - 'a';
            if(temp->children[idx] == nullptr) return false;
            temp = temp->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */