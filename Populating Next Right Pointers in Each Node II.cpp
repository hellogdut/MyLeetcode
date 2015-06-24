/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connectRight(root);
    }
    // 因为不是按树的 level 来执行连接
    // 可能会出现上层还未连接，导致下一层没法跨越空白区域
    // 按level 连接需要一个队列，因为题目要求 O(1)空间。
    // 所以只好分两次做了。
    // 第一次连接同个节点的左右子节点。
    // 第二次连接子节点到隔壁节点

    /*  发现先遍历右边的话，就可以解决上面的问题 !!! */
    void connectRight(TreeLinkNode* curr)
    {
        if(curr == NULL)
            return;
        // 连接节点左右子节点
        if(curr -> left)
            curr -> left -> next = curr -> right;
        // 连接隔壁子节点
        if(curr -> next)
        {
            TreeLinkNode* avlRight = NULL;
            TreeLinkNode* right = curr -> next;
            // 尽力找到一个右边可以连接的点
            while(right)
            {
                avlRight = right -> left ? right -> left : right -> right;
                if(avlRight)
                    break;
                right = right -> next;
            }
            // 找一个左边可以连接的点
            TreeLinkNode* avlLeft = curr -> right ?  curr -> right : curr -> left;
            if(avlLeft)
                avlLeft -> next = avlRight;
        }
        connectRight(curr -> right);
        connectRight(curr -> left);
        
    }
};
