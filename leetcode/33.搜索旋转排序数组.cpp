#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] == target)
                return mid;

            // 左半部分有序    [0, mid]
            if(nums[l] <= nums[mid]) {
                // target 在有序的左半部分内    [l, mid]
                if(target >= nums[l] && target < nums[mid])
                    r = mid;
                else 
                    l = mid + 1;
            }

            // 右半部分有序
            else {
                // target 在有序的右半部分内    [mid + 1, r - 1]
                if(target > nums[mid] && target <= nums[r - 1])
                    l = mid + 1;
                else r = mid;
            }
        }
        return -1;
    }
};