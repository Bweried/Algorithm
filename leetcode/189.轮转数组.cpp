#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * method 1
 * 时间复杂度: O(n)
 * 空间复杂度: O(k)
 */
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         vector<int> ans;
//         int n = nums.size();

//         // 解决k过大的问题
//         k %= n;

//         for(int i = n - k; i < n; i++)
//             ans.push_back(nums[i]);

//         for(int i = n - k - 1; i >= 0; i--)
//             nums[i + k] = nums[i];
        
//         for(int i = 0; i < k; i++)
//             nums[i] = ans[i];
//     }
// };


/**
 * method 2
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;  // 处理k过大的情况

        // 三次翻转实现
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};