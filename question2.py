class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def insertInMiddle(self, head, x):
        new_node = Node(x)
        if head is None:
            return new_node

        slow = head
        fast = head

        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        new_node.next = slow.next
        slow.next = new_node

        return head

def printList(head):
    current = head
    values = []
    while current:
        values.append(str(current.data))
        current = current.next
    print(' '.join(values))



arr_str = input().strip()  
x_str = input().strip()    


arr = list(map(int, arr_str.split())) if arr_str else []
x = int(x_str)


if not arr:
    head = None
else:
    head = Node(arr[0])
    current = head
    for val in arr[1:]:
        current.next = Node(val)
        current = current.next


sol = Solution()
head = sol.insertInMiddle(head, x)


printList(head)
