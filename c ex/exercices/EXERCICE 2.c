// EXERCICE 2 : DOUBLY LINKED LIST:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
} Node;

// create a new node:
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//add node at the end:
Node* addnode(Node* head, int val) {
    Node* newNode = createNode(val);
    if (head==NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

//  merge two doubly linked lists:
Node* mergedoublell(Node* head1, Node* head2) {
    if (head1==NULL) return head2;
    if (head2==NULL) return head1;

    Node* mergedHead = NULL;
    Node* mergedTail = NULL;

    if (head1->val < head2->val) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }
    mergedTail = mergedHead;

    while (head1 && head2) {
        if (head1->val < head2->val) {
            mergedTail->next = head1;
            head1->prev = mergedTail;
            head1 = head1->next;
        } else {
            mergedTail->next = head2;
            head2->prev = mergedTail;
            head2 = head2->next;
        }
        mergedTail = mergedTail->next;
    }

    if (head1) {
        mergedTail->next = head1;
        head1->prev = mergedTail;
    } else if (head2) {
        mergedTail->next = head2;
        head2->prev = mergedTail;
    }

    return mergedHead;
}

// display a doubly linked list:
void DisplaydLL(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d", temp->val);
        if (temp->next) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// create a doubly linked list:
Node* createList() {
    Node* head = NULL;
    int n, val;


    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("enter the value of the  %d node: ", i + 1);
        scanf("%d", &val);
        head = addnode(head, val);
    }
    return head;
}


int main() {
    printf("Enter the number of nodes in the first double linked list:\n");
    Node* list1 = createList();

    printf("Enter the number of nodes in the secend  double linked list:\n");
    Node* list2 = createList();

    Node* mergedHead = mergedoublell(list1, list2);

    printf("Merged  Doubly Linked List:\n");
    DisplaydLL(mergedHead);

    return 0;
}
