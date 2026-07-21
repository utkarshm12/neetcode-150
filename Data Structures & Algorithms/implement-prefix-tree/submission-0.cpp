class Node{
public:
    Node* links[26];
    bool eow;

    Node(){
        for(int i = 0; i < 26; i++) links[i] = NULL;
        eow = false;
    }
};

class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->links[word[i]-'a'] == NULL) node->links[word[i]-'a'] = new Node();
            node = node->links[word[i]-'a'];
        }
        node->eow = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->links[word[i]-'a'] == NULL) return false;
            node = node->links[word[i]-'a'];
        }
        return node->eow;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(node->links[prefix[i]-'a'] == NULL) return false;
            node = node->links[prefix[i]-'a'];
        }
        return true;
    }
};
