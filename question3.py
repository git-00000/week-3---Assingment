# delete node in a linked list

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def append(head, data):
    if head is None:
        return Node(data)
    temp = head
    while temp.next:
        temp = temp.next
    temp.next = Node(data)
    return head

def deleteNode(head, x):
    if head is None:
        return head

    if x == 1:
        return head.next

    temp = head
    for _ in range(x - 2):
        if temp is None or temp.next is None:
            return head
        temp = temp.next

    if temp.next is None:
        return head

    temp.next = temp.next.next
    return head

def print_list(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()


n = int(input("Enter number of nodes: "))
head = None

print("Enter the elements:")
for _ in range(n):
    val = int(input())
    head = append(head, val)

x = int(input("Enter the position to delete (1-based index): "))

head = deleteNode(head, x)

print("Linked list after deletion:")
print_list(head)
