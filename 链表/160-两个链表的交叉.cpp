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
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         std::set<ListNode*> node_set;
         while(headA){
         	node_set.insert(headA);
         	headA = headA->next;
         }
         while(headB){
         	if(node_set.find(headB)!= node_set.end()){
         	    return headB;
         	}
         	headB = headB->next;
         }
         return NULL;
    }
};

