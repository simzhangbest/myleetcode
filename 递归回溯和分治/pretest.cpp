//
// Created by fwq on 2019/1/28.
//

#include <stdio.h>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

void add_to_vector(ListNode* head, std::vector<int>& vec) {
    if(!head) {
        return;
    }

    vec.push_back(head->val);
    add_to_vector(head->next, vec);
}

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);

    a.next = &b;
    b.next = &c;
    c.next = &d;

    std::vector<int> vec;
    add_to_vector(&a, vec);
    for (int i = 0; i < vec.size(); ++i) {
        printf("[%d]", vec[i]);
    }
    printf("\n");
    return 0;
}