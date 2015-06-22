class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        ListNode node(0);
        node.next = head;
        ListNode* prev = head;
        ListNode* curr = head;
        while(curr)
        {
            if(curr -> val == prev -> val)
            {
                prev -> next = curr -> next;
                curr = curr -> next;
            }
            else
            {
                prev = curr;
                curr = curr -> next;
            }
        }
        return node.next;
        
    }
};
