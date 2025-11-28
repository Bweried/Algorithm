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
//         int n = nums.size();

//         if(n == 1)
//             return nums[0];

//         if(n == 2)
//             return max(nums[0], nums[1]);

//         vector<int> dp1(n);
//         dp1[0] = nums[0];
//         dp1[1] = max(nums[0], nums[1]);

//         for(int i = 2; i < n - 1; i++)
//             dp1[i] = max(dp1[i - 1], nums[i] + dp1[i - 2]);

//         vector<int> dp2(n);
//         dp2[0] = nums[1];
//         dp2[1] = max(nums[1], nums[2]);
        
//         for(int i = 2; i < n - 1; i++)
//             dp2[i] = max(dp2[i - 1], nums[i + 1] + dp2[i - 2]);

//         return max(dp1[n - 2], dp2[n - 2]);
//     }
// };


/**
 * method 2
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    // 复用 LeetCode.198 代码
    int rob1(vector<int>& nums, int start, int end) {
        int f0 = 0, f1 = 0;
        for(int i = start; i < end; i++) {
            int new_f = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // nums[0] + rob1(nums, 2, n - 1) 是为了防止只有一个元素的情况
        return max(nums[0] + rob1(nums, 2, n - 1), rob1(nums, 1, n));
    }
};