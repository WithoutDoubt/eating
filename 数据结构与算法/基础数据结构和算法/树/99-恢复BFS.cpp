/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *first;
    TreeNode *second;
    TreeNode *prev;

    void recoverTree(TreeNode *root)
    {
        first = NULL;
        second = NULL;
        prev = new TreeNode(INT_MIN); // 第一次prev 是要和 root 叶节点比的。

        traverse(root);
        swap(first->val, second->val);
    }

    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;

        traverse(root->left);

        // 第一个节点是 prev > root 取 prev
        // 第二个节点是 prev > root 取 root，前提是 第一个节点找到了

        // 本质上 两个 位置 交换了，就是会导致以上的情况。所以我们找到这种情况，再把它换回来

        if (first == NULL && prev->val > root->val)
            first = prev;

        if (first != NULL && prev->val > root->val)
            second = root;

        // prev 保存当前节点，为下一次比较做准备
        prev = root;

        traverse(root->right);
    }
};