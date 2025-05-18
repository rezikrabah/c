#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int val;
    struct Node *next;
} Node;

// Function to create a linked list
Node* createList(int n) {
    Node *head = NULL; // Start with an empty list
    Node *tail = NULL; // Maintain a tail for appending
    int x;

    for (int i = 0; i < n; i++) {
        // Allocate memory for a new node
        Node *new_node = (Node*)malloc(sizeof(Node));
        if (new_node == NULL) { // Check for memory allocation failure
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }

        // Input the value for the node
        printf("Enter the value of node %d: ", i + 1);
        scanf("%d", &x);

        new_node->val = x;
        new_node->next = NULL;

        // Append the node to the list
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return head;
}

// Function to display the linked list
void displayList(Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int n1, n2;

    // Create the first list
    printf("Enter the number of nodes in list 1 (1 to 10): ");
    scanf("%d", &n1);
    if (n1 <= 0 || n1 > 10) {
        printf("Invalid number of nodes for list 1. Please enter a value between 1 and 10.\n");
        return 1;
    }
    Node *list1 = createList(n1);
    printf("List 1:\n");
    displayList(list1);

    // Create the second list
    printf("Enter the number of nodes in list 2 (1 to 10): ");
    scanf("%d", &n2);
    if (n2 <= 0 || n2 > 10) {
        printf("Invalid number of nodes for list 2. Please enter a value between 1 and 10.\n");
        return 1;
    }
    Node *list2 = createList(n2);
    printf("List 2:\n");
    displayList(list2);

    return 0;
}
