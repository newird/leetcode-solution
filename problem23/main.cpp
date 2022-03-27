#include <iostream>
#include<vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        const int n = lists.size();
        if(n <= 1) return  lists[0];
        ListNode* head = lists[0];
        for(int i = 1; i < n;++i){
            head = mergeTwoLists(lists[i],head);
        }
        return head;

    }
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
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
