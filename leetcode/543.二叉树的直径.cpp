#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans;
    }

    int depth(TreeNode* root) {
        if (!root) return 0; // 空节点深度为 0
        int m = depth(root->left);  // 左子树深度
        int n = depth(root->right); // 右子树深度
        ans = max(ans, m + n); // 更新最大直径
        return max(m, n) + 1; // 返回当前节点的深度
    }
};