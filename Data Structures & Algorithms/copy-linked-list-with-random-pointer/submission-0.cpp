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
        // if(head == NULL) return NULL;

        Node* h1 = new Node(0);
        Node* temp1 = head, *temp2 = h1;

        unordered_map<Node*, Node*> mp;

        while(temp1 != NULL){
            temp2->next = new Node(temp1->val);
            mp[temp1] = temp2->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        for(auto it : mp){
            if(it.first->random != NULL){
                it.second->random = mp[it.first->random];
            }
        }

        return h1->next;


    }
};
