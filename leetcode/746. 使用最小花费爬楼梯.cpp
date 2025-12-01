#include<iostream>
#include<vector>
using namespace std;

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();

//         // 表示爬到第 i 层的最小花费
//         // 默认第一步不花体力
//         // dp[0] = 0
//         // dp[1] = 0
//         // dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
//         vector<int> dp(n + 1);  
//         dp[0] = 0;
//         dp[1] = 0;
//         for(int i = 2; i <= n; i++)
//             dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//         return dp[n];
//     }
// };


/**
 * 优化时间复杂度
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int f0 = 0, f1 = 0;
        for(int i = 2; i <= n; i++) {
            int new_f = min(f1 + cost[i - 1], f0 + cost[i - 2]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};