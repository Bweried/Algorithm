#include<iostream>
#include<vector>
using namespace std;


/**
 * method 1
 * 暴力解法（不符合题目要求）
 */
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> v(nums1.begin(), nums1.end());
//         for(auto x : nums2)
//             v.push_back(x);

//         sort(v.begin(), v.end());

//         int n = v.size();
//         if(n % 2)
//             return v[n / 2];
//         else 
//             return double(v[n / 2 - 1] + v[n / 2]) / 2.0;
//     }
// };


/**
 * method 2
 * O(m + n)
 */
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
//         if(a.size() > b.size())
//             swap(a, b);   // 保证下面的 i 可以从 0 开始枚举
        
//         int m = a.size(), n = b.size();
//         a.insert(a.begin(), INT_MIN); // 最左边插入 -∞
//         b.insert(b.begin(), INT_MIN);
//         a.push_back(INT_MAX); // 最右边插入 ∞
//         b.push_back(INT_MAX);

//         // 枚举 nums1 有 i 个数在第一组
//         // 那么 nums2 有 j = (m + n + 1) / 2 - i 个数在第一组
//         int i = 0, j = (m + n + 1) / 2;
//         while(1) {
//             if(a[i] <= b[j + 1] && a[i + 1] > b[j]) {
//                 int max1 = max(a[i], b[j]);  // 第一组的最大值
//                 int min2 = min(a[i + 1], b[j + 1]);  // 第二组的最小值
//                 return (m + n) % 2 ? max1 : (max1 + min2) / 2.0;
//             }
//             i++;
//             j--;
//         }
//     }
// };


/**
 * method 3
 * method 2 的小优化
 * O(m + n)
 */
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
//         if(a.size() > b.size())
//             swap(a, b);

//         int m = a.size(), n = b.size();
//         a.insert(a.begin(), INT_MIN); // 最左边插入 -∞
//         b.insert(b.begin(), INT_MIN);
//         a.push_back(INT_MAX); // 最右边插入 ∞
//         b.push_back(INT_MAX);

//         // 优化点
//         // 当 a[i + 1] > b[j] 时，同时也满足 a[i] <= b[j + 1]
//         // 故只需判断这一个条件即可
//         int i = 0, j = (m + n + 1) / 2;
//         while(a[i + 1] <= b[j]) {
//             i++;
//             j--;
//         }

//         int max1 = max(a[i], b[j]);
//         int min2 = min(a[i + 1], b[j + 1]);
//         return (m + n) % 2 ? max1 : (max1 + min2) / 2.0;
//     }
// };


/**
 * method 4
 * 二分法
 * O(lon(m + n))
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size() > b.size())
            swap(a, b);

        int m = a.size(), n = b.size();
        a.insert(a.begin(), INT_MIN); // 最左边插入 -∞
        b.insert(b.begin(), INT_MIN);
        a.push_back(INT_MAX); // 最右边插入 ∞
        b.push_back(INT_MAX);

        // i ∈ [1, m + 1)
        int left = 1, right = m + 1;
        while(left < right) {
            int i = left + (right - left) / 2;   // mid
            int j = (m + n + 1) / 2 - i;
            if(a[i] <= b[j + 1])
                left = i + 1;   // 缩小区间为 [i + 1, right)
            else
                right = i;   // 缩小区间为 [left, i)
        }

        // 循环结束时 left 是第一个不合法的位置
        int i = left - 1;
        int j = (m + n + 1) / 2 - i;

        int max1 = max(a[i], b[j]);
        int min2 = min(a[i + 1], b[j + 1]);

        return ((m + n) % 2) ? max1 : (max1 + min2) / 2.0;
    }
};