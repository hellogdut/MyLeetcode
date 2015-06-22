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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> _queue;
        vector<vector<int>> result;
        _queue.push(root);

        getOrder(result,_queue);
        reverse(result.begin(),result.end());
        return result;
    }
    void getOrder(vector<vector<int>>& result,queue<TreeNode*>& _queue)
    {
        queue<TreeNode*> q;
        vector<int> vec;
        while(!_queue.empty())
        {
            TreeNode* node = _queue.front();
            _queue.pop();
            if(node)
            {
                vec.push_back(node -> val);
                q.push(node -> left);
                q.push(node -> right);
            }
        }
        
        if(vec.size())
        {
            _queue.swap(q);
            result.push_back(vec);
            return getOrder(result,_queue);
        }
    }
};
