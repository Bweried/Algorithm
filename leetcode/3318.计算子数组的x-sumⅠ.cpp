#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        // 共有 n - k + 1 个子数组
        for(int i = 0; i < n - k + 1; i++) {
            vector<pair<int, int>> hash(51);
            // 初始化  记录数字和频次
            for(int j = 1; j <= 50; j++)
                hash[j] = {0, j};
            for(int j = i; j < i + k; j++)
                hash[nums[j]].first++;

            // 排序  找到 x 个最多的元素
            sort(hash.begin(), hash.end(), [](auto &a, auto &b){
                if (a.first != b.first) return a.first > b.first;
                    return a.second > b.second;
            });

            int sum = 0;
            for(int j = 0; j < x; j++)
                sum += hash[j].first * hash[j].second;
            
            ans.push_back(sum);
        }
        return ans;
    }
};