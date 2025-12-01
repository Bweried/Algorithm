#include<iostream>
#include<vector>
using namespace std;

// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> ans(n + 1);
//         ans[0] = 1;
//         ans[1] = 1;
//         for(int i = 2; i <= n; i++)
//             ans[i] = ans[i - 2] + ans[i - 1];
        
//         return ans[n];
//     }
// };


/**
 * method 2
 * 时间复杂度：O(1)
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        
        int f1 = 1, f2 = 2;
        for(int i = 3; i <= n; i++) {
            int new_f = f1 + f2;
            f1 = f2;
            f2 = new_f;
        }
        return f2;
    }
};