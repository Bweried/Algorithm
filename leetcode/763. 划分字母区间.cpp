#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


/**
 * method 1
 * 哈希表 + 双指针
 */
// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         int n = s.size();
//         vector<int> ans;
//         unordered_map<int, int> mp;
//         for(int c : s) 
//             mp[c]++;
//         int l = 0, r = 0;
//         int pos = 0;  // 上次截断位置
//         while(r < n) {
//             mp[s[r]]--;  // 右指针所指字符出现次数--
//             if(mp[s[r]] == 0) {  // 右指针所指字符出现次数为 0，移动左指针
//                 while(l < r && mp[s[l]] == 0)
//                     l++;
//             }
//             else{
//                 r++;
//                 continue;
//             }
//             if(l == r) {
//                 ans.push_back(r - pos + 1);
//                 pos = r + 1;   // 下一次分割的起始位置
//             }
//             r++;
//         }
//         return ans;
//     }
// };


/**
 * method 2
 * 合并区间
 */
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int last[26];
        for(int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;  // 每个字母最后出现的下标
        }

        vector<int> ans;
        int start = 0, end = 0;
        for(int i = 0; i < n; i++) {
            end = max(end, last[s[i] - 'a']);  // 更新当前区间右端点的最大值
            if(end == i) {  // 当前区间合并完毕
                ans.push_back(end - start + 1);
                start = i + 1;  // 下一个区间的左端点
            }
        }
        return ans;
    }
};