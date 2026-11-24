#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// functions
void display(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//creating
struct Node* createNode(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}


struct Node* concat(struct Node* h1, struct Node* h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    struct Node* temp = h1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = h2;
    return h1; // Fixed: return h1, not h2
}

struct Node* reverse(struct Node* h1) {
    if (h1 == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* prev = NULL;
    struct Node* curr = h1;
    struct Node* nxt = NULL;

    while (curr != NULL) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    display(prev);
    return prev;
}


void sort(struct Node* h1) {
    if (h1 == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* t1;
    struct Node* t2;
    int temp;

    for (t1 = h1; t1 != NULL; t1 = t1->next) {
        for (t2 = t1->next; t2 != NULL; t2 = t2->next) {
            if (t1->data > t2->data) {
                temp = t1->data;
                t1->data = t2->data;
                t2->data = temp;
            }
        }
    }
    display(h1);
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int choice, val;

    while (1) {
        printf("\n======== MENU =========\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display Lists\n");
        printf("4. Reverse List 1\n");
        printf("5. Sort List 1\n");
        printf("6. Concatenate List 1 and List 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value List 1: ");
                scanf("%d", &val);
                head1 = createNode(head1, val);
                break;
            case 2:
                printf("Enter value List 2: ");
                scanf("%d", &val);
                head2 = createNode(head2, val);
                break;
            case 3:
                printf("List 1: ");
                display(head1);
                printf("\n");
                printf("List 2: ");
                display(head2);
                break;
            case 4:
                printf("Reversed List 1: ");
                head1 = reverse(head1);
                break;
            case 5:
                printf("Sorted List 1: ");
                sort(head1);
                break;
            case 6:
                head1 = concat(head1, head2);
                head2 = NULL;
                printf("Concatenated List 1: ");
                display(head1);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

