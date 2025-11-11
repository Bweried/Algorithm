#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // p 在前   q 在后
        ListNode *p = dummy, *q = dummy;

        // 移动指针   p指向开始的前一个结点   q指向最后一个结点
        for(int i = 0; i < left - 1; i++)
            p = p->next;
        for(int i = 0; i < right; i++)
            q = q->next;

        // 记录后续结点
        ListNode* nxtNode = q->next;

        // 截断后续结点
        ListNode* start = p->next;
        q->next = nullptr;

        p->next = reverseList(start);

        start->next = nxtNode;

        return dummy->next;

    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while(cur != nullptr) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};