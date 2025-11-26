#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;   // 当前能跳到的最远位置
        
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxReach)   // 跳不过来
                return false;

            maxReach = max(maxReach, i + nums[i]);

            // 已经能够跳到终点 提前结束
            if(maxReach >= nums.size() - 1)
                return true;
        }
        return true;   // 遍历结束都没挂，说明能到
    }
};