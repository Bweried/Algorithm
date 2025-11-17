#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;   // 新鲜橘子数量

        // 把腐烂橘子添加到队列中
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});  
                else if(grid[i][j] == 1)
                    fresh++;              
            }

        // 如果没有新鲜橘子，返回 0
        if (fresh == 0) return 0;
        
        // 初始化结果
        int ans = -1;
        // 遍历方向
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) {
            int t = q.size();
            ans++;   // 每轮结果 + 1
            while(t--) {
                auto [x, y] = q.front();
                q.pop();

                for(auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    // 越界 及 非腐烂橘子判断
                    if(nx < 0 || nx >= r || ny < 0 || ny >= c || grid[nx][ny] != 1)
                        continue;
                    
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
        }
        
        return fresh == 0 ? ans : -1;
    }
};