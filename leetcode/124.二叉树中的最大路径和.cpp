#include<iostream>
#include<algorithm>
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
    int ans = INT_MIN;

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* node) {
        if (!node) return 0;

        // 递归得到左右子树的"贡献值"（对父节点有正贡献的最大和）
        int left = max(dfs(node->left), 0);   // 负数不要，取 0
        int right = max(dfs(node->right), 0);

        // 以当前节点为"最高点"（path 中间点）的最大路径和，可能包含左右两个分支
        ans = max(ans, left + right + node->val);

        // 返回给父节点：从当前节点向上能延伸的最大单侧路径和（只能选一边延伸）
        return node->val + max(left, right);
    }
};
