#include<iostream>
#include<vector>
using namespace std;


/**
 * method 1
 * dp
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    int integerBreak(int n) {
        // dp[i] 表示整数 i 拆成若干整数相加 该若干整数乘积的最大值
        vector<int> dp(n + 1);
        dp[2] = 1;
        // dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)))
        // 其中：
        // j * (i - j) 是单纯的把整数拆分为 两个数 相乘
        // j * dp[i - j] 是拆分成 两个及两个以上 的数相乘
        for(int i = 3; i <= n; i++) 
            for(int j = 1; j <= i - 1; j++)
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));

        return dp[n];
    }
};


/**
 * method 2
 * 数论
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;

        // 每次拆成 x 个3，如果剩下是 4，则保留 4
        int ans = 1;
        while(n > 4) {
            ans *= 3;
            n -= 3;
        }
        ans *= n;
        return ans;
    }
};