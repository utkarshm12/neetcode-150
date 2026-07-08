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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head, *temp2 = head;
        ListNode* link = head;
        int n = 0, c = 0;

        while(temp != NULL){
            n++;
            if(n%k == 0){
                ListNode* next_link = temp2;
                temp = temp->next;
                ListNode* prev = temp;
                ListNode* next;
                while(temp2 != temp){
                    next = temp2->next;
                    temp2->next = prev;
                    prev = temp2;
                    temp2 = next;
                }
                if(c == 0) head = prev;
                if(c > 0) link->next = prev;
                link = next_link;
                cout << link->val << endl;
                c ++;
            }
            else temp = temp->next;
        }

        // if(n%k == 0){
        //         ListNode* prev = temp;
        //         ListNode* next;
        //         while(temp2 != temp){
        //             next = temp2->next;
        //             temp2->next = prev;
        //             prev = temp2;
        //             temp2 = next;
        //         }
        //         if(c == 1) head = prev;
        //         if(c > 1) link->next = prev;
        // }
        
        return head;
    }
};
