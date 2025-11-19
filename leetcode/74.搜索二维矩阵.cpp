#include<iostream>
#include<vector>
using namespace std;


/**
 * method 1
 * 两次二分查找
 */
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int r = matrix.size(), c = matrix[0].size();
//         // 从下往上找  如果某列的第一个元素 < target  且其下一列的第一个元素 > target  则 pos 为该列索引
//         int pos = -1;
//         int left = 0, right = r;
//         while(left < right) {
//             int mid = left + (right - left) / 2;
//             if(matrix[mid][0] <= target) {
//                 pos = mid;
//                 left = mid + 1;
//             }
//             else right = mid;
//         }

//         if(pos == -1)
//             return false;

//         left = 0, right = c;
//         while(left < right) {
//             int mid = left + (right - left) / 2;
//             if(matrix[pos][mid] < target) left = mid + 1;
//             else if(matrix[pos][mid] > target) right = mid;
//             else return true;
//         }
//         return false;
//     }
// };


/**
 * method 2
 * 一次二分  将 二维数组 逻辑上转换为 一维数组
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        int left = 0, right = r * c;
        while(left < right) {
            int mid = left + (right - left) / 2;
            int x = matrix[mid / c][mid % c];
            if(x < target)
                left = mid + 1;
            else if(x > target)
                right = mid;
            else
                return true;
        }
        return false;
    }
};