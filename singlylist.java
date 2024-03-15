class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class singlylist {
    Node head;

    void insertAtBeginning(int data) {
        Node new_node = new Node(data);
        new_node.next = head;
        head = new_node;
    }

    void insertAtEnd(int data) {
        Node new_node = new Node(data);
        if (head == null) {
            head = new_node;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = new_node;
    }

    void insertInMid(int data, int key) {
        Node new_node = new Node(data);
        if (head == null) {
            head = new_node;
            return;
        }
        Node temp = head;
        while (temp != null && temp.data != key) {
            temp = temp.next;
        }
        if (temp == null) {
            System.out.println("Key not found in the list");
            return;
        }
        new_node.next = temp.next;
        temp.next = new_node;
    }

    void deleteNode(int key) {
        Node temp = head;
        Node prev = null;

        if (temp != null && temp.data == key) {
            head = temp.next;
            return;
        }

        while (temp != null && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }

        if (temp == null) {
            System.out.println("Key not found in the list");
            return;
        }

        prev.next = temp.next;
    }

    void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + "-");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        singlylist list = new singlylist();

        // Insert nodes
        list.insertAtEnd(1);
        list.insertAtEnd(2);
        list.insertAtEnd(3);
        list.insertAtEnd(4);

        System.out.print("Initial List: ");
        list.printList();

        System.out.print("After inserting in mid: ");
        list.insertInMid(5, 6);
        list.printList();

        // Delete a node
        System.out.print("After deleting 3: ");
        list.deleteNode(2);
        list.printList();

        // Insert at beginning
        System.out.print("After inserting 5 at beginning: ");
        list.insertAtBeginning(0);
        list.printList();
    }
}