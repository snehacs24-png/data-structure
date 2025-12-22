#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Staff {
    int staffID;
    char name[50];
    char department[10];
    struct Staff *next;
};

struct Staff *head = NULL;


struct Staff* createNode(int id, char name[], char dept[]) {
    struct Staff *newNode = (struct Staff*)malloc(sizeof(struct Staff));
    newNode->staffID = id;
    strcpy(newNode->name, name);
    strcpy(newNode->department, dept);
    newNode->next = NULL;
    return newNode;
}

void addAtBeginning() {
    int id;
    char name[50], dept[10];

    printf("Enter Staff ID: ");
    scanf("%d", &id);
    printf("Enter Staff Name: ");
    scanf("%s", name);
    printf("Enter Department: ");
    scanf("%s", dept);

    struct Staff *newNode = createNode(id, name, dept);
    newNode->next = head;
    head = newNode;

    printf("Staff added at the beginning successfully.\n");
}


void addAtEnd() {
    int id;
    char name[50], dept[10];

    printf("Enter Staff ID: ");
    scanf("%d", &id);
    printf("Enter Staff Name: ");
    scanf("%s", name);
    printf("Enter Department: ");
    scanf("%s", dept);

    struct Staff *newNode = createNode(id, name, dept);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Staff *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Staff added at the end successfully.\n");
}


void insertAtPosition() {
    int pos, id;
    char name[50], dept[10];

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter Staff ID: ");
    scanf("%d", &id);
    printf("Enter Staff Name: ");
    scanf("%s", name);
    printf("Enter Department: ");
    scanf("%s", dept);

    struct Staff *newNode = createNode(id, name, dept);


    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        printf("Staff inserted at position %d.\n", pos);
        return;
    }

    struct Staff *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Staff inserted at position %d.\n", pos);
    }
}


void deleteByPosition() {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Staff *temp = head;

    if (pos == 1) {
        head = head->next;
        printf("Deleted Staff ID: %d\n", temp->staffID);
        free(temp);
        return;
    }

    struct Staff *prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
    } else {
        prev->next = temp->next;
        printf("Deleted Staff ID: %d\n", temp->staffID);
        free(temp);
    }
}


void searchStaff() {
    int choice, id;
    char name[50];

    printf("Search by:\n1. Staff ID\n2. Staff Name\nEnter choice: ");
    scanf("%d", &choice);

    struct Staff *temp = head;
    int found = 0;

    if (choice == 1) {
        printf("Enter Staff ID: ");
        scanf("%d", &id);

        while (temp != NULL) {
            if (temp->staffID == id) {
                printf("Staff Found: ID=%d, Name=%s, Dept=%s\n",
                       temp->staffID, temp->name, temp->department);
                found = 1;
                break;
            }
            temp = temp->next;
        }
    } else if (choice == 2) {
        printf("Enter Staff Name: ");
        scanf("%s", name);

        while (temp != NULL) {
            if (strcmp(temp->name, name) == 0) {
                printf("Staff Found: ID=%d, Name=%s, Dept=%s\n",
                       temp->staffID, temp->name, temp->department);
                found = 1;
                break;
            }
            temp = temp->next;
        }
    } else {
        printf("Invalid choice.\n");
        return;
    }

    if (!found)
        printf("Staff not found.\n");
}


void displayList() {
    struct Staff *temp = head;

    if (temp == NULL) {
        printf("Staff list is empty.\n");
        return;
    }

    printf("\n--- Staff Allotment List ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Department: %s\n",
               temp->staffID, temp->name, temp->department);
        temp = temp->next;
    }
    printf("----------------------------\n");
}


int main() {
    int choice;

    while (1) {
        printf("\n===== STAFF ALLOTMENT MENU =====\n");
        printf("1. Add Staff at Beginning\n");
        printf("2. Add Staff at End\n");
        printf("3. Insert Staff at Position\n");
        printf("4. Delete Staff by Position\n");
        printf("5. Search Staff\n");
        printf("6. Display Staff List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addAtBeginning(); break;
            case 2: addAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteByPosition(); break;
            case 5: searchStaff(); break;
            case 6: displayList(); break;
            case 7: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

