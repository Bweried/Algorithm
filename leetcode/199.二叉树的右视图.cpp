#include<iostream>
#include<vector>
#include<queue>
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
 * 层序遍历
 */
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         if(!root)
//             return ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()) {
//             int n = q.size();
//             while(n--) {
//                 auto cur = q.front();
//                 // 说明为最右边的节点  存入ans
//                 if(n == 0){
//                     ans.push_back(cur->val);
//                 }
//                 if(cur->left) q.push(cur->left);
//                 if(cur->right) q.push(cur->right);
//                 q.pop();
//             }
//         }
//         return ans;
//     }
// };


/**
 * method 2
 * 递归
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }

    void dfs(TreeNode* root, int depth, vector<int>& ans) {
        if(!root)
            return;
        
        // 如果当前深度还没记录任何节点，说明这是该层第一个访问到的节点
        if(depth == ans.size())
            ans.push_back(root->val);

        // 先递归右子树，再递归左子树
        // 这样每一层第一个访问到的节点一定是“最右边”的
        dfs(root->right, depth + 1, ans);
        dfs(root->left, depth + 1, ans);
    }
};