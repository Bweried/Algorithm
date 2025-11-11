#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// method 1 -> 先水平翻转  再沿主对角线翻转
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         // 水平翻转
//         for(int i = 0; i < n/2; i++)
//             for(int j = 0; j < n; j++)
//                 swap(matrix[i][j], matrix[n - i - 1][j]);
        
//         // 沿对角线翻转
//         for(int i = 0; i < n; i++) 
//             for(int j = 0; j < i; j++)
//                 swap(matrix[i][j], matrix[j][i]);
//     }
// };


// method 2 -> 先转置  再垂直翻转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
                
        for(auto & row : matrix)
            reverse(row.begin(), row.end());
    }
};