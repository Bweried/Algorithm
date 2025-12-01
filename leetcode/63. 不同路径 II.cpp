#include<iostream>
#include<vector>
using namespace std;

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();

//         // dp[i][j] 表示从 (0, 0) 到 (i, j) 的不同路径个数
//         vector<vector<int>> dp(m, vector<int>(n, 0));

//         if(obstacleGrid[0][0] == 0) dp[0][0] = 1;
//         // 第一列若上方无障碍物且自身不为障碍物 则路径个数为 1
//         for(int i = 1; i < m; i++)
//             if(obstacleGrid[i - 1][0] == 0 && obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1)
//                 dp[i][0] = 1;

//         // 第一行若左边无障碍物且自身不为障碍物 则路径个数为 1
//         for(int j = 1; j < n; j++)
//             if(obstacleGrid[0][j - 1] == 0 && obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1)
//                 dp[0][j] = 1;

//         // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
//         for(int i = 1; i < m; i++) {
//             for(int j = 1; j < n; j++) {
//                 if(obstacleGrid[i][j] == 1)
//                     continue;
//                 // 如果上方有障碍物 则只能从左边来
//                 if(obstacleGrid[i - 1][j] == 1)
//                     dp[i][j] = dp[i][j - 1];

//                 // 如果左边有障碍物 则只能从上方来
//                 else if(obstacleGrid[i][j - 1] == 1)
//                     dp[i][j] = dp[i - 1][j];
                
//                 else
//                     dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };


/**
 * 优化代码写法
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        //如果在起点或终点出现了障碍  直接返回0
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 一旦遇到obstacleGrid[i][0] == 1的情况就停止dp[i][0]的赋值1的操作，dp[0][j]同理
        for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for(int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};