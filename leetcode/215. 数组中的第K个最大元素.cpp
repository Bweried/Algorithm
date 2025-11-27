#include<iostream>
#include<queue>
#include<vector>
using namespace std;


/**
 * method 1
 * 优先队列
 * O(nLogK)
 */
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size();
//         priority_queue<int, vector<int>, greater<>> pq;  // 小根堆

//         for(int i = 0; i < n; i++) {
//             int x = nums[i];
//             if(pq.size() == k) {
//                 if(x > pq.top()) {
//                     pq.pop();
//                     pq.push(x);
//                 }
//             }
//             else
//                 pq.push(x);            
//         }
//         return pq.top();
//     }
// };


/**
 * method 2
 * 快排思想
 * O(n)
 */
class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        // 在子数组 [left, right] 中随机选择一个基准元素 pivot
        int i = left + rand() % (right - left + 1);
        int pivot = nums[i];
        // 把 pivot 与子数组第一个元素交换，避免 pivot 干扰后续划分，从而简化实现逻辑
        swap(nums[i], nums[left]);

        i = left + 1;
        int j = right;
        while(true) {
            while(i <= j && nums[i] < pivot) i++;
            // 此时nums[i] >= pivot

            while(i <= j && nums[j] > pivot) j--;
            // 此时nums[j] <= pivot

            if(i >= j)
                break;

            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        swap(nums[left], nums[j]);
        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        int n = nums.size();
        int target_index = n - k;   // 目标元素下标为 n - k
        int left = 0, right = n - 1;
        while(true) {
            int i = partition(nums, left, right);

            if(i == target_index)
                return nums[i];
            
            else if(i > target_index)
                // 第 k 大元素在 [left, i - 1] 中
                right = i - 1;

            else 
                // 第 k 大元素在 [i + 1, right] 中
                left = i + 1;
        }
    }
};