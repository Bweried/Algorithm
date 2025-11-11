#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

// 暴力解法
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size(), n2 = nums2.size();
//         vector<int> ans(n1);
//         for(int i = 0; i < n1; i++) {
//             int flag = 0;
//             int index = 0;
//             for(int j = 0; j < n2; j++)
//                 if(nums2[j] == nums1[i]) {
//                     index = j;
//                     break;
//                 }
//             for(int j = index + 1; j < n2; j++){
//                 if(nums2[j] > nums1[i]) {
//                     ans[i] = nums2[j];
//                     flag = 1;
//                     break;
//                 }
//             }
//             if(!flag)
//                 ans[i] = -1;
//         }
//         return ans;
//     }
// };


// 单调栈  从左到右
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> idx;  // 记录 nums1 中元素对应的下标
        for(int i = 0; i < nums1.size(); i++)
            idx[nums1[i]] = i;

        vector<int> ans(nums1.size(), -1);
        stack<int> st;
        for(int i = 0; i < nums2.size(); i++) {
            int x = nums2[i];
            while(!st.empty() && x > st.top()) {
                ans[idx[st.top()]] = x;
                st.pop();
            }
            if(idx.find(x) != idx.end())
                st.push(x);
        }
        return ans;
    }
};
