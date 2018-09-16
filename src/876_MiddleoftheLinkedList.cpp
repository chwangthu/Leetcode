/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* first = head, *second = head;
        while(first -> next != NULL && second -> next != NULL) {
            first = first -> next;
            second = second -> next;
            if(second -> next != NULL) {
                second = second -> next;
                if(second -> next == NULL) break;
            }
            else {
                break;
            }
        }
        return first;
    }
};
