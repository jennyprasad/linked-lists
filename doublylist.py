class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    # Function to insert a node at the beginning of the list
    def insertAtBeginning(self, data):
        new_node = Node(data)
        if self.head is not None:
            new_node.next = self.head
            self.head.prev = new_node
        self.head = new_node

    # Function to insert a node at the end of the list
    def insertAtEnd(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        temp.next = new_node
        new_node.prev = temp

    # Function to display the doubly linked list
    def display(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.next
        print()

# Main function to test the implementation
dll = DoublyLinkedList()

# Insert some elements
dll.insertAtEnd(10)
dll.insertAtEnd(20)
dll.insertAtBeginning(30)
dll.insertAtEnd(40)

# Display the list
print("Doubly linked list: ", end="")
dll.display()