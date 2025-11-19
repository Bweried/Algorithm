#include<iostream>
#include<vector>
using namespace std;


/**
 * method 1
 * O(N + logN)
 */
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int l = 0, r = nums.size();
//         while(l < r) {
//             int mid = l + (r - l) / 2;
//             if(nums[mid] < target)
//                 l = mid + 1;
//             else 
//                 r = mid;
//         }

//         // 不存在
//         if(l == nums.size() || nums[l] != target)
//             return {-1, -1};
//         else {
//             // l 为第一个  往后扩展
//             int end = l;
//             while(end < nums.size() && nums[end] == target)
//                 end++;
//             return {l, end - 1};
//         }
//     }
// };


/**
 * method 2
 * 两次二分
 * O(logN)
 */
class Solution {
public:
    int binary_search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = binary_search(nums, target);
        if(start == nums.size() || nums[start] != target)
            return {-1, -1};
        int end = binary_search(nums, target + 1) - 1;
        return {start, end};
    }
};