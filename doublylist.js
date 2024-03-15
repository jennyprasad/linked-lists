class Node {
    constructor(data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
    }

    // Function to insert a node at the beginning of the list
    insertAtBeginning(data) {
        const newNode = new Node(data);
        if (this.head !== null) {
            newNode.next = this.head;
            this.head.prev = newNode;
        }
        this.head = newNode;
    }

    // Function to insert a node at the end of the list
    insertAtEnd(data) {
        const newNode = new Node(data);
        if (this.head === null) {
            this.head = newNode;
            return;
        }
        let temp = this.head;
        while (temp.next !== null) {
            temp = temp.next;
        }
        temp.next = newNode;
        newNode.prev = temp;
    }

    // Function to display the doubly linked list
    display() {
        let temp = this.head;
        while (temp !== null) {
            process.stdout.write(temp.data + " ");
            temp = temp.next;
        }
        process.stdout.write("\n");
    }
}

// Main function to test the implementation
const dll = new DoublyLinkedList();

// Insert some elements
dll.insertAtEnd(10);
dll.insertAtEnd(20);
dll.insertAtBeginning(30);
dll.insertAtEnd(40);

// Display the list
process.stdout.write("Doubly linked list: ");
dll.display();