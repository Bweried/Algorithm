#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

template<typename T, typename Compare = less<T>>
class LazyHeap {
private:
    priority_queue<T, vector<T>, Compare> pq;
    unordered_map<T, int> remove_cnt;  // 每个元素剩余需要删除的次数
    size_t sz = 0;  // 实际大小

    // 正式执行删除操作
    void apply_remove() {
        while(!pq.empty() && remove_cnt[pq.top()] > 0) {
            remove_cnt[pq.top()]--;
            pq.pop();
        }
    }

public:
    size_t size() {
        return sz;
    }

    // 删除
    void remove(T x) {
        remove_cnt[x]++;  // 懒删除
        sz--;
    }

    // 查看堆顶
    T top() {
        apply_remove();
        return pq.top();
    }

    // 出堆
    T pop() {
        apply_remove();
        sz--;
        T x = pq.top();
        pq.pop();
        return x;
    }

    // 入堆
    void push(T x) {
        pq.push(x);
        sz++;
    }

    // push(x) 然后 pop()
    T push_pop(T x) {
        if(sz > 0 && Compare()(x, top())) {
            pq.push(x);
            x = pq.top();
            pq.pop();
        }
        return x;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans;
        LazyHeap<double> left;   // 大根堆
        LazyHeap<double, greater<>> right;   // 小根堆

        for(int i = 0; i < n; i++) {
            int in = nums[i];

            if(left.size() == right.size())
                left.push(right.push_pop(in));
            else
                right.push(left.push_pop(in));

            // 窗口没满，继续滑动
            if(i < k - 1)
                continue;

            // 计算中位数
            if(k % 2)
                ans.push_back(left.top());
            else
                ans.push_back((left.top() + right.top()) / 2.0);

            // 删除滑出元素
            int out = nums[i - k + 1];
            if(out <= left.top()) {   // 说明在左边
                left.remove(out);
                if(left.size() < right.size())
                    left.push(right.pop());  // 平衡堆大小
            }
            else {
                right.remove(out);
                if(left.size() > right.size() + 1)
                    right.push(left.pop());
            }
        }

        return ans;
    }
};