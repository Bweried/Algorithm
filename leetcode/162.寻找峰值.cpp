#include<iostream>
#include<vector>
using namespace std;


/**
 * method 1
 * [0, n)
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(mid + 1 < nums.size() && nums[mid] < nums[mid + 1])
                l = mid + 1;
            else 
                r = mid;
        }
        return l;
    }
};


/**
 * method 2
 * [0, n - 1]
 */
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         if (nums.size() == 1) return 0;

//         int l = 0, r = nums.size() - 1;
//         while(l < r) {
//             int mid = l + (r - l) / 2;

//             // mid + 1 永远不会越界， 因为循环条件中限定了 l < r，而 r = n - 1
//             if(nums[mid] < nums[mid + 1])
//                 // 峰值在右边
//                 l = mid + 1;
//             else 
//                 r = mid;
//         }
//         return l;
//     }
// };