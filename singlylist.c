#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node *create_node(int data) {
    node *n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insert_at_beginning(node **head, int data) {
    node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_in_mid(node **head, int data, int key) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node* temp = *head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf ("Key not found in the list\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_node(node **head, int key) {
    node* temp = *head;
    node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found in the list\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printlist(node *head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d-", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes
    insert_at_end(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);

    printf("Initial List: ");
    printlist(head);

    printf("After inserting in mid: ");
    insert_in_mid(&head, 5, 6);
    printlist(head);

    // Delete a node
    printf("After deleting 3: ");
    delete_node(&head, 2);
    printlist(head);

    // Insert at beginning
    insert_at_beginning(&head, 0);
    printf("After inserting 5 at beginning: ");
    printlist(head);

    return 0;
}