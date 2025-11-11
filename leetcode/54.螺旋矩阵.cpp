#include<iostream>
#include<vector>
using namespace std;

class Solution {
    static constexpr int DIRS[4][2] = {
        {0, 1}, 
        {1, 0},
        {0, -1},
        {-1, 0}
    };  // 右下左上
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n);
        int i = 0, j = 0, di = 0;
        for(int k = 0; k < m * n; k++) {
            ans[k] = matrix[i][j];
            matrix[i][j] = INT_MAX;   // 做标记 已访问过
            int x = i + DIRS[di][0], y = j + DIRS[di][1];   // 计算下一步位置
            if(x >= m || x < 0 || y < 0 || y >= n || matrix[x][y] == INT_MAX)
                di = (di + 1) % 4;   // 右转 90°
            i += DIRS[di][0];
            j += DIRS[di][1];  // 走下一步
        }
        return ans;
    }
};