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

        if(head == NULL) return NULL;

        Node* temp = head;
        while(temp != NULL){
            Node* new_node = new Node(temp->val);
            new_node->next = temp->next;
            temp->next = new_node;
            temp = new_node->next;
        }

        temp = head;
        Node* new_head = temp->next;
        Node* temp_cpy = temp->next;

        while(temp != NULL) {
            if(temp->random != NULL) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        temp = head;

        while(temp != NULL){
            temp->next = temp_cpy->next;
            temp = temp->next;
            if(temp == NULL) break;
            temp_cpy->next = temp->next;
            temp_cpy = temp_cpy->next;
        }

        return new_head;

    }
};
