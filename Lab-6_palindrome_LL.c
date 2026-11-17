#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
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

struct Node* createReverse(struct Node* head) {
    struct Node* temp = head;
    struct Node* revHead = NULL;

    while (temp != NULL) {
        struct Node *newNode = createNode(temp->data);
        newNode->next = revHead;
        revHead = newNode;
        temp = temp->next;
    }
    return revHead;
}

bool isPalindrome(struct Node* head) {
    struct Node* revHead = createReverse(head);
    struct Node* p1 = head;
    struct Node* p2 = revHead;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data != p2->data) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(20);
    head->next->next->next->next = createNode(10);

    printf("List: ");
    printList(head);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}
