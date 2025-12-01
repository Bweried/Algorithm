#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j] 表示从 (0, 0) 到 (i, j) 的不同路径个数
        // 只能向下或者向右移动一步
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // 第一行 或 第一列 都只有一条路径
        for(int i = 1; i <= m; i++) dp[i][1] = 1;
        for(int j = 1; j <= n; j++) dp[1][j] = 1;

        for(int i = 2; i <= m; i++)
            for(int j = 2; j <= n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m][n];
    }
};