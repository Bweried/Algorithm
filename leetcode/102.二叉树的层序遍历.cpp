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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            // 插入空向量
            ans.push_back(vector<int>());
            while(n--) {
                auto cur = q.front();
                q.pop();
                ans.back().push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return ans;
    }
};