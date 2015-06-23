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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

       vector<vector<int>> result;
       deque<TreeNode*> _deque;
       _deque.push_back(root);
       // 0 left -> right
       // 1 right -> left
       visitFrom(0,result,_deque);
       return result;
        
    }
    void visitFrom(int direction,vector<vector<int>>& result,deque<TreeNode*>& _deque)
    {
       vector<int> solution;
       deque<TreeNode*> dq;

       while(!_deque.empty())
       {
          // right -> left
          if(direction)
          {
             TreeNode* pn = _deque.back();
             _deque.pop_back();
             if(!pn)
                continue;
             solution.push_back(pn -> val);
             dq.push_back(pn -> right);
             dq.push_back(pn -> left);
          }
          else
          {
             TreeNode* pn = _deque.front();
             _deque.pop_front();
             if(!pn)
                continue;
             solution.push_back(pn -> val);
             dq.push_back(pn -> left);
             dq.push_back(pn -> right);
          }
       }
       if(solution.size())
       {
          result.push_back(solution);
          if(direction)
             reverse(dq.begin(),dq.end());
          _deque.swap(dq);
          return visitFrom(!direction,result,_deque);
       }
    }

};
