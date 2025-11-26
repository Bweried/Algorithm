#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Min = 10000;   // 用一个很大的值初始化，表示历史最低买入价
        int ans = 0;       // 最大利润，初始为 0（不交易则利润为 0）

        // 遍历每天的股价
        for (auto x : prices) {
            Min = min(x, Min);   // 更新历史最低价格，表示最划算的买入价
            ans = max(ans, x - Min); // 尝试今天卖出，计算是否能得到更高利润
        }

        return ans;  // 返回最大利润
    }
};
