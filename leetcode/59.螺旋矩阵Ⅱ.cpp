#include<iostream>
#include<vector>
using namespace std;

class Solution {
    static constexpr int DIRS[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int i = 0, j = 0, dir = 0;
        for(int k = 1; k <= n * n; k++){
            ans[i][j] = k;

            int x = i + DIRS[dir][0], y = j + DIRS[dir][1];
            if(x < 0 || x >= n || y < 0 || y >= n || ans[x][y] != 0)
                dir = (dir + 1) % 4;
            
            i += DIRS[dir][0];
            j += DIRS[dir][1];
        }
        return ans;
    }
};