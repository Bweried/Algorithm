#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* head2 = reverseList(mid);

        while(head2) {
            if(head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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