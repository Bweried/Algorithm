#include<iostream>
#include<vector>
using namespace std;


// mySolution
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, 1);
//         // 计算 前缀乘积 及 后缀乘积
//         vector<int> pre(n, 1), suf(n, 1);

//         pre[0] = nums[0];
//         for(int i = 1; i <= n-1; i++)
//             pre[i] = pre[i - 1] * nums[i];
        
//         suf[n-1] = nums[n-1];
//         for(int i = n-2; i >= 0; i--)
//             suf[i] = suf[i+1] * nums[i];
        
//         for(int i = 0; i < n; i++) {
//             if(i == 0)
//                 ans[i] = suf[1];
//             else if(i == n-1)
//                 ans[i] = pre[n-2];
//             else
//                 ans[i] = pre[i-1] * suf[i+1];
//         }

//         return ans;
//     }
// };


// other People's
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        for(int i = 1; i < n; i++)
            pre[i] = pre[i - 1] * nums[i - 1];

        vector<int> suf(n, 1);
        for(int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] * nums[i + 1];
    
        vector<int> ans(n, 1);
        for(int i = 0; i < n; i++)
            ans[i] = pre[i] * suf[i];
        return ans;
    }
};