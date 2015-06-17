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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode node(0);
        node.next = head;
        int times = 0;
        int k = 0;
        ListNode* p = head;
        while(1)
        {
           k = 0;
           while(k < n && p)
           {
              p = p -> next;
              k++;
           }
           if(p != NULL)
              times++;
           else
           {
              k = n - k;
              break; 
           }
        }
        ListNode* q = &node;
        p = node.next;
        for(int i = 0;i < times * n - k;++i)
        {
           q = p;
           p = p -> next;
        }
        q -> next = p -> next;
        return node.next;
    }
};
