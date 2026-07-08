class Node{
    public:
    int key, val;
    Node* prev, *next;
    Node();
    Node(int k, int v){
        key = k;
        val = v;
        next = prev = NULL;
    } 
    Node(int k, int v, Node* p){
        key = k;
        val = v;
        prev = p;
        next = NULL;
    }
};

class LRUCache {
    int c;
    unordered_map<int, Node*> mp;
    Node* head, *tail;

public:
    LRUCache(int capacity) {
        c = capacity;
        head = tail = NULL;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        exsists(key, mp[key]->val);
        return mp[key]->val;

    }
    
    void put(int key, int value) {
        if(head == NULL){
            head = tail = new Node(key, value);
            mp[key] = head;
            return;
        }
        if(mp.find(key) != mp.end()){
            exsists(key, value);
            return;
        }

        Node *temp = new Node(key, value, tail);
        tail->next = temp;
        tail = tail->next;
        mp[key] = tail;

        if(mp.size() > c){
            head = head->next;
            mp.erase(head->prev->key);
            delete(head->prev);
            head->prev = NULL;
        }
    }

    void exsists(int key, int value){
        Node* temp = mp[key];
            if(temp == tail){
                temp->val = value;
                return;
            }
            if(temp == head){
                head = head->next;
                temp->prev = tail;
                tail->next = temp;
                temp->next = NULL;
                tail = tail->next;
                tail->val = value;
                return;
            }

            remove(temp);
            tail->next = new Node(key, value, tail);
            tail = tail->next;
            mp[key] = tail;
    }

    void remove(Node* temp){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete(temp);
    }
};
