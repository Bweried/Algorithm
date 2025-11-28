#include<iostream>
#include<vector>
using namespace std;


/**
 * method 1
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();  // 获取房屋数量

//         // 如果只有一个房屋，直接返回该房屋金额
//         if(n == 1)
//             return nums[0];

//         // 初始化 dp 数组，dp[i] 表示偷窃前 i 间房屋时最大可得金额
//         vector<int> dp(n);

//         // 第一间房屋只能偷，金额就是 nums[0]
//         dp[0] = nums[0];

//         // 第二间房屋可以选择偷第一间或第二间，取较大金额
//         dp[1] = max(nums[0], nums[1]);

//         // 从第三间房屋开始，计算每间房屋的最大偷窃金额
//         for(int i = 2; i < n; i++) {
//             // 对比：1. 不偷当前房屋，最大金额为 dp[i-1]；2. 偷当前房屋，最大金额为 nums[i] + dp[i-2]
//             dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
//         }

//         // 返回最后一间房屋的最大可偷金额
//         return dp[n - 1];
//     }
// };


/**
 * method 2
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int f0 = 0, f1 = 0;  // 初始化 f0 和 f1，表示偷窃前 i-2 间房屋和前 i-1 间房屋的最大金额
        // f0 表示不偷当前房屋时的最大金额，f1 表示偷到当前房屋时的最大金额

        for(int x : nums) {  // 遍历每一间房屋
            // 计算当前房屋的最大金额（偷当前房屋或不偷当前房屋）
            int new_f = max(f1, f0 + x);  // max(f1, f0 + x) 选择不偷当前房屋或偷当前房屋后的最大金额

            f0 = f1;  // 更新 f0 为之前的 f1（即不偷当前房屋时的最大金额）
            f1 = new_f;  // 更新 f1 为当前的 new_f（即偷当前房屋时的最大金额）
        }

        return f1;  // 最终返回偷窃所有房屋的最大金额
    }
};
