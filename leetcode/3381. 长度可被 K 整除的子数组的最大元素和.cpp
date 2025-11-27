#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // 前缀和数组
        vector<long long> prefix(n + 1);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<long long> min_s(k, LLONG_MAX / 2);  // 防止下溢
        long long ans = LLONG_MIN;
        for(int j = 0; j < prefix.size(); j++) {
            int i = j % k;
            ans = max(prefix[j] - min_s[i], ans);
            min_s[i] = min(min_s[i], prefix[j]);
        }
        return ans;
    }
};