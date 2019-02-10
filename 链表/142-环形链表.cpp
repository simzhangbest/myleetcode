/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *	解题思路：使用快慢指针，找到meet的点，从head 和 meet 出发，两指针速度一致，相遇即为环的起点 
 */
#include<iostream>
using namespace std; 
struct ListNode {
	int val;
 	ListNode *next;
  	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
   		ListNode *fast = head;
   		ListNode *slow = head;
   		ListNode *meet = NULL;
		while(fast){
			slow = slow->next;
			fast = fast->next;
			
			if(!fast){
				return NULL;
			}
			fast = fast->next;
			if(fast == slow){
				meet = fast;				
				break;
			}
		} 
		if(meet == NULL){
			return NULL;
		}
		
		while(head && meet){
			if(head == meet){
				return head;
			}
			head = head->next;
			meet = meet->next;
		}
  		return NULL;
    }
    
};

int main(void){
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	ListNode g(7);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &c;
	Solution solve;
	ListNode *node = solve.detectCycle(&a);
	if(node){
		cout << node->val << endl;
	}
	else{
		cout << "no circle" << endl;
	}
	return 0;
}