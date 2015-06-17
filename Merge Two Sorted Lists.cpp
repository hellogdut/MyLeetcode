/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define MAX_INT (-(0x01 << (sizeof(int) * 8 - 1)) - 1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode head(0);
        ListNode* node = &head;

        while(l1 || l2)
        {
            int x = MAX_INT;
            if(l1 && l2)
            {
                if(l1 -> val < l2 -> val)
                {
                    x = l1 -> val;
                    l1 = l1 -> next;
                }
                else
                {
                    x = l2 -> val;
                    l2 = l2 -> next;
                }
            }
            else if(l1)
            {
                x = l1 -> val;
                l1 = l1 -> next;
            }
            else if (l2)
            {
                x = l2 -> val;
                l2 = l2 -> next;
            }
            node -> next = new ListNode(x);
            node = node -> next;

        }
        return head.next;     
    }
};
