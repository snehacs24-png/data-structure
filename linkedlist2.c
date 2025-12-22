#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *head2 = NULL;

void insertEnd(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertEnd2(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head2 == NULL) {
        head2 = newNode;
        return;
    }

    struct node *temp = head2;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList() {
    if (head == NULL || head->next == NULL) {
        printf("List too short to sort.\n");
        return;
    }

    struct node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted.\n");
}

void reverseList() {
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed.\n");
}


void concatenate() {
    if (head == NULL) {
        head = head2;
        head2 = NULL;
        printf("Concatenation done.\n");
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    head2 = NULL;
    printf("Concatenation done.\n");
}


int main() {

    insertEnd(5);
    insertEnd(3);
    insertEnd(8);
    insertEnd(1);

    printf("Original List 1:\n");
    printList(head);


    insertEnd2(10);
    insertEnd2(20);

    printf("List 2:\n");
    printList(head2);


    sortList();
    printList(head);

    reverseList();
    printList(head);


    concatenate();
    printList(head);

    return 0;
}
