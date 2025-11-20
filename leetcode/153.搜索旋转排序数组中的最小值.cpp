#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        // 只有一个元素
        if(r == 0)
            return nums[0];

        while(l < r) {
            int mid = l + (r - l) / 2;
            
            // 最小值在右边
            if(nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l];
    }
};