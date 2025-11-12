#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 如果当前节点 root 为 nullptr，说明已经递归到叶子节点的子节点，返回 nullptr
        // 如果当前节点 root 等于 p 或 q，说明找到了其中一个目标节点，直接返回当前节点 root
        if(root == nullptr || root == p || root == q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right)   // 左右都找到
            return root;  // 当前节点是最近公共祖先
        
        // 如果只有左子树找到，就返回左子树的返回值
        // 如果只有右子树找到，就返回右子树的返回值
        // 如果左右子树都没有找到，就返回 nullptr（注意此时 right = nullptr）
        return left ? left : right;
    }
};