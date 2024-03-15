class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

class doublylist {
    Node head;

    doublylist() {
        head = null;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        if (head != null) {
            newNode.next = head;
            head.prev = newNode;
        }
        head = newNode;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
        newNode.prev = temp;
    }

    // Function to display the doubly linked list
    void display() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}


    public static void main(String[] args) {
        doublylist dll = new doublylist();

        // Insert some elements
        dll.insertAtEnd(10);
        dll.insertAtEnd(20);
        dll.insertAtBeginning(30);
        dll.insertAtEnd(40);

        // Display the list
        System.out.print("Doubly linked list: ");
        dll.display();
    }
