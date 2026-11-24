#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void display(struct Node* head, const char* name) {
    if (head == NULL) {
        printf("%s is empty\n", name);
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed into stack: %d\n", newNode->data);
}
ng
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    printf("Popped value: %d\n", temp->data);
    free(temp);
}

void enque(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted into queue: %d\n", newNode->data);
}

void deque() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    front = temp->next;
    if (front == NULL) {
        rear = NULL;
    }
    printf("Deleted value from queue: %d\n", temp->data);
    free(temp);
}

int main() {
    struct Node* top = NULL;
    int choice, val;

    while (1) {
        printf("\n======== MENU =========\n");
        printf("1. Push into stack\n");
        printf("2. Insert into queue\n");
        printf("3. Display stack and queue\n");
        printf("4. Pop stack\n");
        printf("5. Delete val in queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(&top, val); 
                break;
            case 2:
                printf("Enter queue value: ");
                scanf("%d", &val);
                enque(val);
                break;
            case 3:
                printf("Stack: ");
                display(top, "Stack");
                printf("Queue: ");
                display(front, "Queue");
                break;
            case 4:
                pop(&top);
                break;
            case 5:
                deque();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
