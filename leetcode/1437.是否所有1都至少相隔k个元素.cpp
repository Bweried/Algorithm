#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int flag = -1;  // 记录是否遇到第一个 1   遇到之后记录 index
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                if(flag != -1) {
                    int dis = i - flag - 1;
                    if(dis < k)
                        return false;
                }
                flag = i;
            }
        }
        return true;
    }
};