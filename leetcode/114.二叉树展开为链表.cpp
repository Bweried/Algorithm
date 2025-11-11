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


/**
 * method 1
 */
// class Solution {
// public:
//     vector<int> v;

//     void flatten(TreeNode* root) {
//         preorder(root);
//         if(v.size() <= 1)
//             return;
//         root->left = nullptr;
//         root->right = nullptr;

//         TreeNode* p = root;
//         for(int i = 1; i < v.size(); i++){
//             p->right = new TreeNode(v[i]);
//             p = p->right;
//         }
//     }

//     void preorder(TreeNode* root) {
//         if(!root)
//             return;
//         v.push_back(root->val);
//         preorder(root->left);
//         preorder(root->right);
//     }
// };


/**
 * method 2
 * 头插法
 */
class Solution {
public:
    TreeNode* head; // 用于记录当前链表的头节点，初始值为 nullptr

    /**
     * 将二叉树展开为链表
     * @param root 二叉树的根节点
     * 
     * 思路：
     * 1. 使用后序遍历的方式（先处理右子树，再处理左子树，最后处理当前节点）。
     * 2. 通过一个全局变量 `head` 来记录当前链表的头节点。
     * 3. 遍历到某个节点时：
     *    - 将当前节点的右子树指向 `head`（即链表的头节点）。
     *    - 将当前节点的左子树置为空。
     *    - 更新 `head` 为当前节点。
     * 4. 递归完成后，整个二叉树会被原地展开为一个单链表，链表的顺序与二叉树的前序遍历顺序一致。
     */
    void flatten(TreeNode* root) {
        if(!root) // 如果当前节点为空，直接返回
            return;
        flatten(root->right); // 递归处理右子树
        flatten(root->left);  // 递归处理左子树
        root->left = nullptr; // 将当前节点的左子树置为空
        root->right = head;   // 将当前节点的右子树指向链表的头节点
        head = root;          // 更新链表的头节点为当前节点
    }
};