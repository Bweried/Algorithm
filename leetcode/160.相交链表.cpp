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
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* p = headA;
//         ListNode* q = headB;
//         while(p != q) {
//             p = p ? p->next : headB;
//             q = q ? q->next : headA;
//         }
//         return p;
//     }
// };

/**
 * method 2
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA), lenB = getLen(headB);
        int diff = abs(lenA - lenB);
        ListNode* p = headA;
        ListNode* q = headB;
        if(lenA > lenB)
            while(diff--)
                p = p->next;
        else 
            while(diff--)
                q = q->next;
        
        while(p != q){
            p = p->next;
            q = q->next;
        }
        return p;
    }

    int getLen(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(p != nullptr) {
            len++;
            p = p->next;
        }
        return len;
    }
};