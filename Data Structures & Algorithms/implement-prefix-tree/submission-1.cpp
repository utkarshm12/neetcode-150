class Node{
public:
    unordered_map<char, Node*> links;
    bool flag;

    Node(){
        flag = false;
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
        for(auto i : word){
            if(!node->links[i]) node->links[i] = new Node();
            node = node->links[i];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(auto i: word){
            if(!node->links[i]) return false;
            node = node->links[i];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto i: prefix){
            if(!node->links[i]) return false;
            node = node->links[i];
        }
        return true;
    }
};
