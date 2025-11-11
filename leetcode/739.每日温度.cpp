#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 从右到左遍历
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int> ans(n);     // 用于存放答案：每个位置 i 需要等待多少天才能升温
//         stack<int> st;          // 单调栈，栈中存放「下标」，保证对应温度单调递减（从栈顶到栈底）

//         // 从后往前遍历，因为未来的温度在后面
//         for (int i = n - 1; i >= 0; i--) {
//             int t = temperatures[i];  // 当前第 i 天的温度

//             // 如果栈顶的温度 <= 当前温度，就不可能是答案，直接弹出
//             // 保证栈中的温度始终比当前温度高（形成单调递减栈）
//             while (!st.empty() && t >= temperatures[st.top()])
//                 st.pop();

//             // 如果栈不为空，说明栈顶的下标对应的温度是「下一个更高温度」
//             // 因此等待天数 = 栈顶下标 - 当前下标
//             if (!st.empty())
//                 ans[i] = st.top() - i;
//             else
//                 ans[i] = 0;  // 栈空表示右侧没有更高温度

//             // 把当前下标入栈，作为之后左侧元素的“未来候选”
//             st.push(i);
//         }

//         return ans;
//     }
// };


// 从左向右遍历
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            int t = temperatures[i];
            while(!st.empty() && t > temperatures[st.top()]){
                int j = st.top();
                ans[j] = i - j;
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};