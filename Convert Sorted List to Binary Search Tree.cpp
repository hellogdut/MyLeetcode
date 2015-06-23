/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head)
        {
           nums.push_back(head -> val);
           head = head -> next;
        }
        return sortedArrayToBST(nums);
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        vector<pair<int,int>> vec;
        vec.push_back(make_pair(0,nums.size() - 1));
        vector<pair<int,int>> tmp;
        TreeNode* root = NULL;
        while(!vec.empty())
        {
            while(!vec.empty())
            {
                auto p = vec.back();
                vec.pop_back();
                int i = p.first;
                int j = p.second;
                if(i > j)
                    continue;
                int mid = (j - i)/2 + i;
                root = addNode(root,nums[mid]);
                tmp.push_back(make_pair(i,mid-1));
                tmp.push_back(make_pair(mid + 1,j));
            }
            vec.swap(tmp);
        }
        return root;
    }
    
    TreeNode* addNode(TreeNode* root,int num)
    {
        TreeNode* node = new TreeNode(num);
        if(!root)
        {
            root = node;
            return root;
        }
        
        TreeNode* prev = root;
        TreeNode* curr = prev;
        while(curr)
        {
            prev = curr;
            if(curr -> val < num)
                curr = curr -> right;
            else if (curr -> val > num)
                curr = curr -> left;
            else
                break;
            
        }
        if(num < prev -> val)
            prev -> left = node;
        else if(num > prev -> val)
            prev -> right = node;
        
        return root;
    }
    
    
};
