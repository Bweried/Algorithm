#include<iostream>
#include<vector>
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
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode* head = new ListNode(-1);

//         for(auto list : lists) {
//             head = mergeTwoLists(head, list);
//         }

//         return head->next;
//     }

//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* head = new ListNode(-1);
//         ListNode* p = head;

//         ListNode* l1 = list1;
//         ListNode* l2 = list2;

//         while(l1 != nullptr && l2 != nullptr) {
//             if(l1->val < l2->val) {
//                 p->next = l1;
//                 l1 = l1->next;
//             }
//             else {
//                 p->next = l2;
//                 l2 = l2->next;
//             }
//             p = p->next;
//         }

//         if(l1 != nullptr) p->next = l1;
//         if(l2 != nullptr) p->next = l2;

//         return head->next;
//     }
// };


/**
 * method 2
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return mergeRange(lists, 0, lists.size() - 1);
    }

    ListNode* mergeRange(vector<ListNode*>& lists, int left, int right) {
        if(left == right) return lists[left];
        int mid = left + (right - left) / 2;
        ListNode* l1 = mergeRange(lists, left, mid);
        ListNode* l2 = mergeRange(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;

        while(l1 && l2) {
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
        p->next = l1 ? l1 : l2;
        return dummy->next;
    }
};