#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        deque<int> q;   // 双端队列 保存下标

        for(int i = 0; i < n; i++) {
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);

            int left = i - k + 1;   // 左边元素出队
            if(q.front() < left)
                q.pop_front();
            
            if(left >= 0)
                ans[left] = nums[q.front()];
        }
        return ans;
    }
};