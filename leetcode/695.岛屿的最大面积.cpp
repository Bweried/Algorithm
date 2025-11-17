#include<iostream>
#include<vector>
using namespace std;


/**
 * method 1
 * 引用传递面积
 */
// class Solution {
// public:
//     int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

//     void dfs(vector<vector<int>>& grid, int i, int j, int& curArea) {
//         int r = grid.size(), c = grid[0].size();

//         if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0)
//             return;

//         grid[i][j] = 0;
//         curArea++;

//         for(auto& d : dirs) {
//             dfs(grid, i + d[0], j + d[1], curArea);
//         }
//     }

//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int ans = 0;
//         int r = grid.size(), c = grid[0].size();
//         for(int i = 0; i < r; i++) {
//             for(int j = 0; j < c; j++) {
//                 if(grid[i][j] == 1)  {
//                     int area = 0;
//                     dfs(grid, i, j, area);
//                     ans = max(ans, area);
//                 }
//             }
//         }
//         return ans;
//     }
// };


/**
 * method 2
 * 递归计算面积
 */
class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>>& grid, int i, int j) {
        int r = grid.size(), c = grid[0].size();
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0)
            return 0;

        int ans = 1;
        grid[i][j] = 0;

        for(auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            ans += dfs(grid, x, y);
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int r = grid.size(), c = grid[0].size();
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};