#include<iostream>
#include<vector>
using namespace std;

// class Solution {
// public:
//     void dfs(vector<vector<char>>& grid, int i, int j) {
//         int r = grid.size();
//         int c = grid[0].size();

//         grid[i][j] = '0';
//         if(i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
//         if(j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
//         if(i + 1 < r && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
//         if(j + 1 < c && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
//     }

//     int numIslands(vector<vector<char>>& grid) {
//         int r = grid.size();
//         if(!r) return 0;
//         int c = grid[0].size();

//         int ans = 0;
//         for(int i = 0; i < r; i++) {
//             for(int j = 0; j < c; j++) {
//                 if(grid[i][j] == '1') {
//                     ans++;
//                     dfs(grid, i, j);
//                 }
//             } 
//         }
//         return ans;
//     }
// };


/**
 * 解法同上，写法不同
 */
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int r = grid.size(), c = grid[0].size();

        // 越界
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] != '1')
            return;

        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        if(!r) return 0;
        int c = grid[0].size();

        int ans = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};