#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * method 1
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 */
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         vector<int> v;
//         ListNode* p = head;
//         while(p != nullptr) {
//             v.push_back(p->val);
//             p = p->next;
//         }
//         sort(v.begin(), v.end());
//         p = head;
//         int i = 0;
//         while(p != nullptr) {
//             p->val = v[i];
//             i++;
//             p = p->next;
//         }
//         return head;
//     }
// };


/**
 * method 2
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
    }
};