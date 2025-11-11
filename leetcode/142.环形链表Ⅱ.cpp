#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * method 1
 */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* slow = head;
//         ListNode* fast = head;

//         // 快慢指针第一次相遇
//         while(fast != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//             if(slow == fast)
//                 break;
//         }

//         // 无环
//         if(fast == nullptr || fast->next == nullptr) return nullptr;

//         // 找入口  慢指针回起点
//         slow = head;
//         while(slow != fast) {
//             slow = slow->next;
//             fast = fast->next;
//         }

//         return slow;
//     }
// };

/**
 * 优化代码写法
 */
class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                while(slow != head) {
                    slow = slow->next;
                    head = head->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
