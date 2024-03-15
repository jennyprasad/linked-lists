class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    insertAtBeginning(data) {
        let new_node = new Node(data);
        new_node.next = this.head;
        this.head = new_node;
    }

    insertAtEnd(data) {
        let new_node = new Node(data);
        if (this.head === null) {
            this.head = new_node;
            return;
        }
        let temp = this.head;
        while (temp.next !== null) {
            temp = temp.next;
        }
        temp.next = new_node;
    }

    insertInMid(data, key) {
        let new_node = new Node(data);
        if (this.head === null) {
            this.head = new_node;
            return;
        }
        let temp = this.head;
        while (temp !== null && temp.data !== key) {
            temp = temp.next;
        }
        if (temp === null) {
            console.log("Key not found in the list");
            return;
        }
        new_node.next = temp.next;
        temp.next = new_node;
    }

    deleteNode(key) {
        let temp = this.head;
        let prev = null;

        if (temp !== null && temp.data === key) {
            this.head = temp.next;
            return;
        }

        while (temp !== null && temp.data !== key) {
            prev = temp;
            temp = temp.next;
        }

        if (temp === null) {
            console.log("Key not found in the list");
            return;
        }

        prev.next = temp.next;
    }

    printList() {
        let temp = this.head;
        while (temp !== null) {
            process.stdout.write(temp.data + "-");
            temp = temp.next;
        }
        console.log();
    }
}

let list = new LinkedList();

// Insert nodes
list.insertAtEnd(1);
list.insertAtEnd(2);
list.insertAtEnd(3);
list.insertAtEnd(4);

process.stdout.write("Initial List: ");
list.printList();

process.stdout.write("After inserting in mid: ");
list.insertInMid(5, 6);
list.printList();

// Delete a node
process.stdout.write("After deleting 3: ");
list.deleteNode(2);
list.printList();

// Insert at beginning
process.stdout.write("After inserting 5 at beginning: ");
list.insertAtBeginning(0);
list.printList();