#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // dp[i] 表示由 i 个节点组成的二叉搜索树共有 dp[i] 个
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};