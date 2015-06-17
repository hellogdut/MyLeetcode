class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode node(0);
        node.next = head;
        ListNode* prev = &node;
        int i = 1;
        ListNode* curr = head;
        while(curr)
        {
            if((i % k) == 0)
            {
                ListNode* p = prev -> next;
                ListNode* next = curr -> next;
                reverse(p,curr);
                prev -> next = curr;
                p -> next = next;
                curr = next;
                prev = p;
            }
            else
            {
                curr = curr -> next;
            }
            ++i;
        }
        
        
        return node.next;
    }
    ListNode* reverse(ListNode* p,ListNode* end)
    {
        ListNode* head = p;
        ListNode* prev = NULL;
        ListNode* curr = p;
        while(curr)
        {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            if(prev == end)
            {
                head -> next = next;
                break;
            }
            
        }
        return prev;
    }
};
// int main()
// {
// //    vector<int> v = {1,2,3,4,5};
// //    Solution s;
// //    ListNode* p = listNodeFromVector(v);
// //    p = s.reverse(p, p -> next -> next);
// //    PrintNode(p);
    
//     vector<int> v = {1,2,3};
//     Solution s;
//     ListNode* p = listNodeFromVector(v);
//     p = s.reverseKGroup(p, 1);
//     PrintNode(p);
// }
    
