#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* p = head;
        ListNode* q = head->next;

        while(p!= nullptr && q != nullptr) {
            p->next = q->next;
            q->next = p;
            prev->next = q;
            
            // 向前移动
            prev = p;
            p = p->next;
            if(p != nullptr) q = p->next;
        }

        return dummy->next;
    }
};

int main() {
    return 0;
}