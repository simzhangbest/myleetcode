/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x) , next(NULL){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = NULL;
        while(head){
        	ListNode *next = head->next; // 备份head->next 
        	head->next = new_head;	// 更新head->next 
        	new_head = head;		//移动 new_head 
        	head = next;			// 遍历 
        }
        return new_head; //返回新的链表头 
    }
};

int main(){
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	a.next = &b;
	b.next = &c;
	Solution solve;
	ListNode *head = &a;
	printf("before reverse:\n");
	while(head){
		cout << head->val << endl;
		head = head->next;
	}
	head = solve.reverseList(&a);
	printf("after reverse:\n");
	while(head){
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}