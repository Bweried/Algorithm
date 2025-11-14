#include<iostream>
#include<vector>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty())
            return nullptr;

        int n = postorder.size();
        // 左子树大小
        int left_size = find(inorder.begin(), inorder.end(), postorder[n - 1]) - inorder.begin();
        // 左子树
        vector<int> post1(postorder.begin(), postorder.begin() + left_size);
        vector<int> post2(postorder.begin() + left_size, postorder.end() - 1);
        vector<int> in1(inorder.begin(), inorder.begin() + left_size);
        vector<int> in2(inorder.begin() + 1 + left_size, inorder.end());

        TreeNode* left = buildTree(in1, post1);
        TreeNode* right = buildTree(in2, post2);
        return new TreeNode(postorder[n - 1], left, right);
    }
};