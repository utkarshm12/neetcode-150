class Node{
public:
    unordered_map<char, Node*> links;
    bool flag = false;
};

class WordDictionary {
    Node* root;
public: 
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char i : word){
            if(!node->links[i]) node->links[i] = new Node();
            node = node->links[i];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        return find(word, 0, root);
    }

    bool find(string word, int i, Node* temproot){
        Node* node = temproot;

        for(int id = i; id < word.size(); id++){
            if(word[id] == '.'){
                for(auto cur : node->links){
                    if(cur.second && find(word, id+1, cur.second)) return true;
                }
                return false;
            }
            else{
                if(!node->links[word[id]]) return false;
            }
            node = node->links[word[id]];
        }

        return node->flag;

    }
};
