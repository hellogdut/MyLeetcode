/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    deque<int> vec;
public:
    BSTIterator(TreeNode *root) {
        enumTreeNode(root);
    }
    void enumTreeNode(TreeNode* p)
    {
        if(p)
        {
            enumTreeNode(p -> left);
            vec.push_back(p -> val);
            enumTreeNode(p -> right);
        }
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !vec.empty();
    }

    /** @return the next smallest number */
    int next() {
        int r = vec.front();
        vec.pop_front();
        return r;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
