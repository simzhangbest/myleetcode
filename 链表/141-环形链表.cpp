// 141 �ж� ��û�л�  142 ������ʼ�ڵ�


 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
#include<iostream>
#include<set>
using namespace std;
struct ListNode {
	int val;
 	ListNode *next;
  	ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> node_set;
        while(head){
        	if(node_set.find(head) != node_set.end()){
	        	return head;
	        }
	        node_set.insert(head);
        	head = head->next;
        }
        return NULL;
    }
};
