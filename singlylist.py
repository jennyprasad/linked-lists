class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

    def insert_in_mid(self, data, key):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        temp = self.head
        while temp and temp.data != key:
            temp = temp.next
        if temp is None:
            print("Key not found in the list")
            return
        new_node.next = temp.next
        temp.next = new_node

    def delete_node(self, key):
        temp = self.head
        if temp is not None and temp.data == key:
            self.head = temp.next
            temp = None
            return
        prev = None
        while temp and temp.data != key:
            prev = temp
            temp = temp.next
        if temp is None:
            print("Key not found in the list")
            return
        prev.next = temp.next
        temp = None

    def print_list(self):
        temp = self.head
        while temp:
            print(temp.data, end="-")
            temp = temp.next
        print()

list = LinkedList()

# Insert nodes
list.insert_at_end(1)
list.insert_at_end(2)
list.insert_at_end(3)
list.insert_at_end(4)

print("Initial List: ", end="")
list.print_list()

print("After inserting in mid: ", end="")
list.insert_in_mid(5, 6)
list.print_list()

# Delete a node
print("After deleting 3: ", end="")
list.delete_node(2)
list.print_list()

# Insert at beginning
print("After inserting 5 at beginning: ", end="")
list.insert_at_beginning(0)
list.print_list()