#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* front = NULL;
struct Node* rear = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("%d pushed into stack\n", value);
}

void pop() {
    if (head == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("%d popped from stack\n", temp->data);
    head = head->next;
    free(temp);
}

void peek() {
    if (head == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", head->data);
}

void displayStack() {
    if (head == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Stack: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d enqueued into queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("%d dequeued from queue\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Peek (Stack)\n");
        printf("4. Display Stack\n");
        printf("5. Enqueue (Queue)\n");
        printf("6. Dequeue (Queue)\n");
        printf("7. Display Queue\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                displayStack();
                break;
            case 5:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 6:
                dequeue();
                break;
            case 7:
                displayQueue();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
