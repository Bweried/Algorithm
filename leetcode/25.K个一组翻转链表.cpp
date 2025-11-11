#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* end = dummy;

        while(true) {
            for(int i = 0; i < k && end != nullptr; i++)
                end = end->next;
            
            if(end == nullptr) break;

            // 下一组的起点
            ListNode* nxtGroup = end->next; 

            // 截断当前组
            ListNode* start = pre->next;
            end->next = nullptr;

            pre->next = reverseList(start);

            start->next = nxtGroup;

            // 移动指针
            pre = start;
            end = pre;
        }
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
