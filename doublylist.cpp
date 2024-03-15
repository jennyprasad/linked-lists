#include <iostream>

using namespace std;

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Class for doubly linked list
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int data) {
        Node* newNode = new Node{data, nullptr, head};
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Function to display the doubly linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Insert some elements
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(30);
    dll.insertAtEnd(40);

    // Display the list
    cout << "Doubly linked list: ";
    dll.display();

    return 0;
}