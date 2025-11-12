#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);

        // 如果数组中已经有 1，则只需要将剩余的 n - ones 个元素变成 1
        if(ones > 0)
            return n - ones;
        
        // 如果没有 1，尝试找到一个子数组，使得其 GCD 为 1
        int minLen = INT_MAX;
        for(int i = 0; i < n; i++) {
            int cur = nums[i];
            for(int j = i + 1; j < n; j++) {
                cur = gcd(cur, nums[j]);
                if(cur == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }

        if(minLen == INT_MAX)
            return -1;

        // 如果找到了 GCD 为 1 的子数组，最少操作次数为子数组长度 - 1 + (n - 1)
        return minLen - 1 + (n - 1);
    }
};

int main() {
    return 0;
}