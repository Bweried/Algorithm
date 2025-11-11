#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;

        int carry = 0;   // 进位

        while(l1 || l2 || carry) {
            if(l1 != nullptr) {
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                carry += l2->val;
                l2 = l2->next;
            }

            ListNode* cur = new ListNode(carry % 10);

            p->next = cur;
            p = cur;

            carry /= 10;
        }

        return dummy->next;
    }
};

int main() {
    return 0;
}