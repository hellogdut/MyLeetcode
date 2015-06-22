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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode node(0);
        node.next = head;
        int count = 1;

        ListNode* prev = &node;
        ListNode* curr = prev -> next;

        while(count < m)
        {
            prev = curr;
            curr = curr -> next;
            count++;

        }
        

        ListNode* next = curr -> next;
        ListNode* prevNext = curr;

        count = n - m;
        while(count)
        {
            // 
            ListNode* last = next ? next -> next : NULL;
            next -> next = curr;
            prev -> next = next;
            prevNext -> next = last;

            // 
            curr = next;
            next = last;
            count--;

        }

        return node.next;



    }
};
