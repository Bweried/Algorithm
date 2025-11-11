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


/**
 * method 1
 */
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         int ans = 0;
//         maxDepth(root, 1, ans);
//         return ans;
//     }

//     void maxDepth(TreeNode* root, int d, int& ans) {
//         if(!root)
//             return;
//         if(ans < d) ans = d;
//         if(root->left)
//             maxDepth(root->left, d + 1, ans);
//         if(root->right)
//             maxDepth(root->right, d + 1, ans);
//     }
// };


/**
 * method 2
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int m = maxDepth(root->left);
        int n = maxDepth(root->right);
        return max(m + 1, n + 1);
    }
};