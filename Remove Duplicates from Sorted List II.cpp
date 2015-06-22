class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        
        ListNode node(0);
        node.next = head;
        ListNode* prev = &node;
        ListNode* curr = prev -> next;
        ListNode* next = curr -> next;
        
        while(next)
        {
            if(next -> val == curr -> val)
            {
                next = next -> next;
                while(next && next -> val == curr -> val)
                    next = next -> next;
                prev -> next = next;
                curr = prev -> next;
                next = curr ? curr -> next : NULL;
            }
            else
            {
                prev = curr;
                curr = next;
                next = next -> next;
            }
        }
        
        
        
        
        return node.next;
        
    }
};
