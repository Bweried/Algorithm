#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
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

//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 0)
//             return nullptr;
//         int mid = n / 2;
//         TreeNode* ans = new TreeNode(nums[mid]);

//         // 平均分为左右子树递归
//         vector<int> left(nums.begin(), nums.begin() + mid);
//         vector<int> right(nums.begin() + mid + 1, nums.end());
        
//         ans->left = sortedArrayToBST(left);
//         ans->right = sortedArrayToBST(right);

//         return ans;
//     }
// };


/**
 * method 2
 */
// class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         return sorted(nums, 0, nums.size() - 1);
//     }

//     TreeNode* sorted(vector<int>& nums, int left, int right) {
//         if(left > right) return nullptr;
//         int mid = left + (right - left) / 2;
//         TreeNode* cur = new TreeNode(nums[mid]);
//         cur->left = sorted(nums, left, mid - 1);
//         cur->right = sorted(nums, mid + 1, right);
//         return cur;
//     }
// };


/**
 * method 3
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if(left > right)
            return nullptr;
        
        int mid = left + (right - left) / 2;
        return new TreeNode(nums[mid], dfs(nums, left, mid - 1), dfs(nums, mid + 1, right));
    }
};