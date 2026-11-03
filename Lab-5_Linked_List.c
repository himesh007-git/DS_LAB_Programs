#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void insertBeginning(struct Node **head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}


void insertEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

   
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertMiddle(struct Node **head, int value, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insertBeginning(head, value);
        return;
    }

    struct Node *temp = *head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}


void deletefirst(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteend(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *p = *head;
    if (p->next == NULL) { 
        free(p);
        *head = NULL;
        return;
    }

    struct Node *q = (*head)->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}


void deleteatindex(struct Node **head, int index) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (index < 1) {
        printf("Invalid position\n");
        return;
    }
    if (index == 1) {
        deletefirst(head);
        return;
    }

    struct Node *p = *head;
    struct Node *q = NULL;
    int i;

    for (i = 1; i < index - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL || p->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    q = p->next;
    p->next = q->next;
    free(q);
}


void display(struct Node **head) {
    struct Node *temp = *head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data); 
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL; // Initialized the head pointer
    int c = 1, choice, pos, val; 

    while (c == 1) {
        printf("\n-----------------------------\n");
        printf("Menu of List operations\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at front\n");
        printf("5. Delete at End\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &val);
                insertBeginning(&head, val); 
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &val);
                insertEnd(&head, val);
                break;
            case 3:
                printf("Enter the value: ");
                scanf("%d", &val);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insertMiddle(&head, val, pos);
                break;
            case 4:
                deletefirst(&head);
                break;
            case 5:
                deleteend(&head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                deleteatindex(&head, pos);
                break;
            case 7:
                display(&head);
                break;
            case 8:
                c = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
