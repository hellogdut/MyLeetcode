class Solution {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(l1 == NULL)
      {
         return l2;
      }
      if(l2 == NULL)
         return l1;
      ListNode* head = l1;
      int in = 0;
      while (l1 && l2)
      {
         int sum = l1->val + l2->val + in;
         in = 0;
         if (sum >=10)
         {
            sum -= 10;
            in = 1;
         }
         l1->val = sum;
      
         if (l1->next == NULL || l2->next == NULL)
            break;
         l1 = l1->next;
         l2 = l2->next;
      }
      if (l1->next == NULL && l2->next == NULL)
      {
         if (in)
            l1->next = new ListNode(in);
         return head;
      }

      if (l1->next == NULL)
         l1->next = l2->next;
      l1 = l1->next;
      
      while (l1)
      {
         int sum = l1->val + in;
         in = 0;
         if (sum >= 10)
         {
            sum -= 10;
            in = 1;
         }
         l1->val = sum;
         if (l1->next == NULL)
            break;
         l1 = l1->next;
      }
      if (in)
         l1->next = new ListNode(in);
      return head;
   }
};

