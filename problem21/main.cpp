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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *head = new ListNode();
        ListNode *p = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            } else {
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }

        }
        while (list1) {
            p->next = list1;
            p = p->next;
            list1 = list1->next;
        }
        while (list2) {
            p->next = list2;
            p = p->next;
            list2 = list2->next;
        }
        return head->next;
    }
};

int main() {
    ListNode *list1 = new ListNode(1, new ListNode(3, new ListNode(4, nullptr)));
    ListNode *list2 = new ListNode(1, new ListNode(2, new ListNode(4, nullptr)));
    Solution solution;
    auto l = solution.mergeTwoLists(list1, list2);
    while (l->next) {
        std::cout << l->val;
        l = l->next;
    }
    return 0;
}
