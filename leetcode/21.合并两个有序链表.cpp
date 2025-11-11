#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* p = head;

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if(l1 != nullptr) p->next = l1;
        if(l2 != nullptr) p->next = l2;

        return head->next;
    }
};