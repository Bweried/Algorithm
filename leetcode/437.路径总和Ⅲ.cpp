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

class Solution {
public:
    int ans;

    int pathSum(TreeNode* root, int targetSum) {
        // 初始化哈希表，记录前缀和为0的路径出现1次
        unordered_map<long long, int> cnt = {{0, 1}};
        dfs(root, 0, targetSum, cnt);
        return ans;
    }

    void dfs(TreeNode* root, long long s, int targetSum, unordered_map<long long, int>& cnt) {
        if (!root) return;

        // 更新当前路径的前缀和
        s += root->val;

        // 检查是否存在前缀和为 (s - targetSum) 的路径
        // 如果存在，说明从某个节点到当前节点的路径和为 targetSum
        ans += cnt[s - targetSum];

        // 将当前前缀和加入哈希表，记录其出现次数
        cnt[s]++;

        // 递归遍历左子树
        dfs(root->left, s, targetSum, cnt);
        // 递归遍历右子树
        dfs(root->right, s, targetSum, cnt);

        // 回溯：撤销当前节点的前缀和计数，避免影响其他路径
        cnt[s]--;
    }
};