# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
import itertools
list1=[1,2,8]
list2=[6,3,9,4]
list3 = itertools.zip_longest(list1,list2)
print(list3)