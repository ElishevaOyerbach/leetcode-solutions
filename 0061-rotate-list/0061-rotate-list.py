# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        if not head or not head.next or k == 0:
            return head
        n = 1
        tail=head
        while tail.next:
            tail=tail.next
            n+=1
        k = k % n
        if k == 0:
            return head
        index = n - k - 1
        newTail = head
        for _ in range(index):
            newTail = newTail.next
        newHead = newTail.next
        tail.next = head

        newTail.next = None
        return newHead

        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        