#include<iostream>
using namespace std;

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) 
            return nullptr;

        // 复制每个节点，把新节点直接插到原节点的后面
        for(Node* cur = head; cur; cur = cur->next->next) {
            cur->next = new Node(cur->val, cur->next, nullptr);
        }

        // 遍历交错链表中的原链表节点
        for(Node* cur = head; cur; cur = cur->next->next) {
            if(cur->random) {
                cur->next->random = cur->random->next;
            }
        }

        // 把交错链表分离成两个链表
        Node* ans = head->next;
        Node* cur = head;
        for(; cur->next->next; cur = cur->next) {
            Node* copy = cur->next;
            cur->next = copy->next;
            copy->next = copy->next->next;
        }
        cur->next = nullptr;
        return ans;
    }
};

int main() {
    return 0;
}