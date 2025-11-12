#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // 前缀和数组
        vector<int> s(n + 1);
        for(int i = 0; i < n; i++)
            s[i + 1] = s[i] + nums[i];

        int ans = 0;
        unordered_map<int, int> mp;
        for(int sj : s) {
            ans += mp.contains(sj - k) ? mp[sj - k] : 0;
            mp[sj]++;
        }
        return ans;
    }
};