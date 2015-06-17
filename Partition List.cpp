/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       
       if(head == NULL)
          return head;

       ListNode node(0);
       node.next = head;
       ListNode* p1 = &node;
       ListNode* p2 = head;
       while(p2 && p2 -> val < x)
       {
          p1 = p2;
          p2 = p2 -> next;
       }
       if(!p2)
          return head;
       while(1)
       {
          ListNode* q1 = p2;
          ListNode* q2 = q1 -> next;
          while(q2 && q2 -> val >= x)
          {
             q1 = q2;
             q2 = q2 -> next;
          }
          if(!q2)
             break;
          q1 -> next = q2 -> next;

          q2 -> next = p2;
          p1 -> next = q2;
          p1 = q2;
       }
       return node.next;
    }
};
