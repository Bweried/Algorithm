#include<iostream>
#include<vector>
using namespace std;


/**
 * method 1
 */
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1) return 0;
        
//         int cur = 0;   // 当前所处位置
//         int ans = 0;

//         while(cur < n - 1) {
//             // 如果这一跳就能到终点
//             if(cur + nums[cur] >= n - 1)
//                 return ans + 1;

//             int bestPos = cur; 
//             int maxReach = 0;

//             // 在当前能跳的范围内，找到下一跳最优的位置
//             for (int j = cur + 1; j <= cur + nums[cur] && j < n; j++) {
//                 if (j + nums[j] > maxReach) {
//                     maxReach = j + nums[j];
//                     bestPos = j;   // 下一跳应该跳到的位置
//                 }
//             }

//             cur = bestPos;  // 真的跳到 bestPos
//             ans++;
//         }
//         return ans;
//     }
// };


/**
 * method 2
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int cur_right = 0;  // 已建造的桥的右端点
        int next_right = 0;  // 下一座桥的右端点的最大值
        for(int i = 0; i + 1 < nums.size(); i++) {
            next_right = max(next_right, i + nums[i]);
            if(i == cur_right) {  // 无路可走，必须建桥
                cur_right = next_right;  // 建桥后，最远可以到达 next_right
                ans++;
            }
        }
        return ans;
    }
};