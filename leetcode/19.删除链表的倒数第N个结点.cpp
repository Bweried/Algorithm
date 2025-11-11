#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* q = head;

        while(n--) p = p->next;

        if(p == nullptr) return head->next;

        while(p->next) {
            q = q->next;
            p = p->next;
        }

        q->next = q->next->next;
        return head;
    }
};

int main() {
    return 0;
}