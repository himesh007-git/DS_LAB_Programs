#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node* removeDuplicates(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* curr = head;
    struct Node* temp = NULL;

    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
    return head;
}


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* head = createNode(10);
    head->next = createNode(10);
    head->next->next = createNode(20);
    head->next->next->next = createNode(30);
    head->next->next->next->next = createNode(30);

    printf("Original list: ");
    printList(head);

    head = removeDuplicates(head);

    printf("After removing duplicates: ");
    printList(head);

    return 0;
}
