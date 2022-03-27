#include <iostream>


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode * p = new ListNode;ListNode*q; ListNode*r;
        p->next = head;
        auto cur = p;
        while(cur->next && cur->next->next){
            q = cur->next;
            r = q->next;
            cur->next = r;
            q->next = r->next;
            r->next =q;
            cur = q;
        }

        return p->next;
    }


};

int main() {
    ListNode * list = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4, nullptr)))) ;
    Solution solution;
    auto l = solution.swapPairs(list);
    while(l){
        std::cout<<l->val;
        l = l->next;
    }

    return 0;
}
