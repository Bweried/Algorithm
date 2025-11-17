#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();

        int ans = 0;

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 1) {
                    for(auto [x, y] : dirs) {
                        int nx = i + x, ny = j + y;
                        if(nx < 0 || nx >= r || ny < 0 || ny >= c || grid[nx][ny] == 0)
                            ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};