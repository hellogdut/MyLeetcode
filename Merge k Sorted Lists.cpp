class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *p,*p1,*p2;
        deque<ListNode*> queue(lists.begin(),lists.end());
        
        while(queue.size() >= 2)
        {
            p1 = queue.back();
            queue.pop_back();
            p2 = queue.back();
            queue.pop_back();
            p = mergeTwoLists(p1,p2);
            queue.push_front(p);
        }
        return queue.size() == 1 ? queue[0] : NULL;
    }
    ListNode* mergeTwoLists(ListNode* p1,ListNode* p2)
    {
        ListNode node(0);
        node.next = p1;
        ListNode* prev = &node;
        
        while(p1 && p2)
        {
            if(p1 -> val < p2 -> val)
            {
                prev = p1;
                p1 = p1 -> next;
            }
            else
            {
                prev -> next = p2;
                p2 = p2 -> next;
                prev = prev -> next;
                prev -> next = p1;
                
            }
        }
        if(p2)
            prev -> next = p2;
        
        return node.next;
    }
};

