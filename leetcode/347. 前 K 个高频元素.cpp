#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;


/**
 * method 1
 * hash表 使用sort排序
 * 时间复杂度：O(nlogn)
 */
// class Solution {
// public:
//     static bool cmp(pair<int, int> a, pair<int, int> b) {
//         return a.second > b.second;
//     }

//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         for(int x : nums)
//             mp[x]++;
//         vector<pair<int, int>> v(mp.begin(), mp.end());
//         sort(v.begin(), v.end(), cmp);
//         vector<int> ans;
//         for(int i = 0; i < k; i++)
//             ans.push_back(v[i].first);
//         return ans;
//     }
// };


/**
 * method 2
 * hash表 维护小顶堆
 * 时间复杂度：O(n)
 */
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         for(int x : nums)
//             mp[x]++;

//         // 小顶堆：按频率排序
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pri;

//         for(auto& p : mp) {
//             pri.push({p.second, p.first});  // (value, key)

//             // 保证堆里只保留频率最高的 k 个
//             if(pri.size() > k)
//                 pri.pop();
//         }

//         vector<int> ans;
//         while(!pri.empty()) {
//             ans.push_back(pri.top().second);
//             pri.pop();
//         }
//         return ans;
//     }
// };


/**
 * method 3
 * 桶排序
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        // 桶的大小
        int max_cnt = 0;
        for(int x : nums) {
            mp[x]++;
            max_cnt = max(max_cnt, mp[x]);
        }
        
        // 把出现次数相同的元素，放到同一个桶中
        vector<vector<int>> bucs(max_cnt + 1);
        for(auto& [k, v] : mp) 
            bucs[v].push_back(k);
        
        vector<int> ans;
        for(int i = max_cnt; i >= 0 && ans.size() < k; i--) {
            ans.insert(ans.end(), bucs[i].begin(), bucs[i].end());
        }

        return ans;
    }
};