"""
    从尾到头打印链表
    
    输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

    示例 1：
        输入：head = [1,3,2]
        输出：[2,3,1]
 
    限制：
        0 <= 链表长度 <= 10000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

from typing import List
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class LinkdedList:
    def __init__(self):
        self.head = None

    def initList(self, data):

        if len(data) > 0:
            self.head = ListNode(data[0])
        else:
            return None

        h = self.head
        p = self.head
        for item in data[1:]:
            node = ListNode(item)
            p.next = node
            p = p.next
        return h

class Solution:

    # array (stack), 36ms, 16.2mb, time o(n), space o(n), input remains intact
    def reversePrint(self, head: ListNode) -> List[int]:

        # input validation
        if head is None:
            return []
        
        # using array
        temp = []
        while head is not None:
            temp.append(head.val)
            head = head.next
        return temp[::-1]

    # recursion, 32ms, 26.7mb, time o(n), space o(n), input remains intact
    def reversePrint2(self, head: ListNode) -> List[int]:

        def recurse(head:ListNode):
            temp.append(head.val)
            if head.next is not None:
                return recurse(head.next)
        
        # input validation
        if head is None:
            return []

        temp = []
        recurse(head)
        return temp[::-1]


if __name__ == '__main__':

    s = Solution()

    ll = LinkdedList()
    input = [
        ll.initList([1, 3, 2]),
        
        ll.initList([]),            # empty linked list
        ll.initList([1]),           # single element list
        ll.initList([None]),        # list of None
        None,                       # None
    ]

    print('-----')
    for item in input:
        print(s.reversePrint(item))
        print(s.reversePrint2(item))
        print('-----')
