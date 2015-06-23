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
    vector<int> rightSideView(TreeNode* root) {

       vector<int> result;
       deque<TreeNode*> _deque;
       _deque.push_back(root);

       // 保证队列中没有空指针
       // 这样省去很多麻烦
       if(!root)
          return result;

       helper(result,_deque);
       return result;

    }
    void helper(vector<int>& result,deque<TreeNode*>& _deque)
    {
       deque<TreeNode*> q;
       TreeNode* pn = _deque.back();
       result.push_back(pn -> val);
       for(auto i : _deque)
       {
          if(i -> left)
             q.push_back(i -> left);
          if(i -> right)
             q.push_back(i -> right);
       }
       if(!q.empty())
       {
          _deque.swap(q);
          return helper(result,_deque);
       }
    }
};
