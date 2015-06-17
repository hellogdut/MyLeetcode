class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode node(0);
        node.next = head;
        ListNode* prev = &node;
        
        ListNode *p1 = head;
        while(p1 && p1 -> next)
        {
            ListNode* p2 = p1 -> next;
            ListNode* p3 = p2 -> next;
            prev -> next = p2;
            p2 -> next = p1;
            p1 -> next = p3;
            prev = p1;
            p1 = p3;
        }
        return node.next;

    }
};
