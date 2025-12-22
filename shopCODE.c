

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Shop {
    int shopID;
    char shopName[50];
    struct Shop *next;
};

struct Shop *head = NULL;


struct Shop* createShop(int id, char name[]) {
    struct Shop *newShop = (struct Shop*)malloc(sizeof(struct Shop));
    if (newShop == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newShop->shopID = id;
    strncpy(newShop->shopName, name, 49);
    newShop->shopName[49] = '\0';
    newShop->next = NULL;

    return newShop;
}


void addShopAtEnd(int id, char name[]) {
    struct Shop *newShop = createShop(id, name);

    if (head == NULL) {
        head = newShop;
        return;
    }

    struct Shop *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newShop;
}


void insertAfterID(int targetID, int newID, char name[]) {
    struct Shop *temp = head;

    while (temp != NULL && temp->shopID != targetID)
        temp = temp->next;

    if (temp == NULL) {
        printf("Shop ID %d not found!\n", targetID);
        return;
    }

    struct Shop *newShop = createShop(newID, name);
    newShop->next = temp->next;
    temp->next = newShop;
}


void removeShop(int id) {
    if (head == NULL) {
        printf("No shops available!\n");
        return;
    }

    struct Shop *temp = head, *prev = NULL;

    if (temp != NULL && temp->shopID == id) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->shopID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Shop ID %d not found!\n", id);
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void searchByName(char name[]) {
    struct Shop *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->shopName, name) == 0) {
            printf("Shop Found: ID=%d, Name=%s\n", temp->shopID, temp->shopName);
            return;
        }
        temp = temp->next;
    }

    printf("Shop with name '%s' not found.\n", name);
}


void displayShops() {
    if (head == NULL) {
        printf("No shops in the mall.\n");
        return;
    }

    struct Shop *temp = head;
    printf("\nShops in the corridor:\n");
    while (temp != NULL) {
        printf("Shop ID: %d | Name: %s\n", temp->shopID, temp->shopName);
        temp = temp->next;
    }
    printf("\n");
}


void freeAllShops() {
    struct Shop *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice, id, targetID;
    char name[50];

    while (1) {
        printf("\n--- Shopping Complex Menu ---\n");
        printf("1. Add Shop at End\n");
        printf("2. Insert Shop After ID\n");
        printf("3. Remove Shop\n");
        printf("4. Search Shop by Name\n");
        printf("5. Display All Shops\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Shop ID: ");
                scanf("%d", &id);
                printf("Enter Shop Name: ");
                scanf("%49s", name);
                addShopAtEnd(id, name);
                break;

            case 2:
                printf("Enter Target Shop ID to insert after: ");
                scanf("%d", &targetID);
                printf("Enter New Shop ID: ");
                scanf("%d", &id);
                printf("Enter New Shop Name: ");
                scanf("%49s", name);
                insertAfterID(targetID, id, name);
                break;

            case 3:
                printf("Enter Shop ID to remove: ");
                scanf("%d", &id);
                removeShop(id);
                break;

            case 4:
                printf("Enter Shop Name to search: ");
                scanf("%49s", name);
                searchByName(name);
                break;

            case 5:
                displayShops();
                break;

            case 6:
                freeAllShops();
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
