/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0; 
        ListNode* temp = head, *prev = NULL;

        while(temp != NULL) temp = temp->next, sz++;

        temp = head;

        while(temp != NULL){
            if(!(sz-n)){
                if(prev == NULL) return head->next;
                else{
                    prev->next = temp->next;
                    return head;
                }
            }
            sz--;
            prev = temp;
            temp = temp->next;
        }
        return head;

    }
};
