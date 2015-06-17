class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k < 1)
            return head;
        
        ListNode node(0);
        node.next = head;
        int n = 0;
        while(head)
        {
            n++;
            head = head -> next;
        }
        k = k % n;
        
        if(n < 2)
            return node.next;
        
        while(k--)
        {
            ListNode* p = node.next;
            ListNode* q = p -> next;
            while(q -> next)
            {
                q = q -> next;
                p = p -> next;
            }
            head = node.next;
            p -> next = NULL;
            q -> next = head;
            node.next = q;
        }
        
        return node.next;
        
    }
};
