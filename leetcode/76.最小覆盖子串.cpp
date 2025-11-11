#include<iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        int need[128] = {0};   // 统计还需要哪些元素
        for(auto c : t)
            need[c]++;

        // left right 维护一个滑动窗口
        // count 用于统计满足t中元素的个数
        int left = 0, right = 0, count = 0;   
        int minLen = INT_MAX, start = 0;
        int window[128] = {0};   // 用于统计s中的元素个数
        while(right < s.size()) {
            // 持续滑动右指针
            char c = s[right];
            window[c]++;
            if(need[c] > 0 && window[c] <= need[c]) count++;
            right++;   // 指针右移

            // 满足要求, 收缩滑动窗口
            while(count == t.size()) {
                // 更新答案
                if(right - left < minLen){
                    minLen = right - left;
                    start = left;
                }

                char lc = s[left];
                if(need[lc] > 0 && window[lc] <= need[lc]) count--;
                window[lc]--;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};