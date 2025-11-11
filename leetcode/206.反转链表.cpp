#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * method 1
 */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == nullptr) return head;   // 链表为空  直接返回
//         if (head->next == nullptr) return head; // 链表长度为1，直接返回

//         // 创建哑节点 dummy，指向原链表的头节点
//         ListNode* dummy = new ListNode(-1);
//         dummy->next = head;

//         ListNode* p = head;
//         ListNode* q = head->next;

//         // 头插法
//         while(q != nullptr) {
//             p->next = q->next;
//             q->next = dummy->next;
//             dummy->next = q;

//             q = p->next;
//         }

//         return dummy->next;
//     }
// };


/**
 * method 2
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
