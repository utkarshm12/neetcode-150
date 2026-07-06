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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1 = list1, *h2 = list2;
        if(h1 == NULL) return h2;
        if(h2 == NULL) return h1;

        ListNode* head = new ListNode();
        ListNode* temp = head;

        while(h1 != NULL || h2 != NULL){
            if(h1 == NULL && h2 != NULL){
                temp->next = h2;
                h2 = h2->next;
            }
            else if(h2 == NULL && h1 != NULL){
                temp->next = h1;
                h1 = h1->next;
            }
            else if(h1->val <= h2->val){
                temp->next = h1;
                h1 = h1->next;
            }
            else{
                temp->next = h2;
                h2 = h2->next;
            }

            temp = temp->next;
        }

        return head->next;
    }
};
