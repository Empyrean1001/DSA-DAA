class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        prev = None
        while(curr != None):
            nextn = curr.next
            curr.next = prev
            prev = curr
            curr = nextn
        return prev
