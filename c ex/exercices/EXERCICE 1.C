// EXERCICE 1:SINGLY LINKED LIST


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Function to create a linked list :

Node* createList(int n) {
    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        printf("Enter value for node %d between 1-9: ", i + 1);
        scanf("%d", &val);

        if (val >= 0 && val < 10) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            if (newNode == NULL) {
                perror("Failed to allocate memory");
                exit(EXIT_FAILURE);
            }

            newNode->val = val;
            newNode->next = head;
            head = newNode;
        } else {
            printf("Invalid value give a number between 1 and 9.\n");
            i--;
        }
    }
    return head;
}

// Function to display a linked list:
void displayList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to add two numbers:
Node* addthetwonumbers(Node* l1, Node* l2) {
    Node* result = NULL;
    Node* tail = NULL;
    Node* prec = NULL; // suivre le dernier nœud de la liste résultante afin de relier le nouveau nœud (temp) à la liste existante
    int retenue = 0;

    while (l1 != NULL || l2 != NULL || retenue) {
        int sum = retenue;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

       retenue = sum / 10;  //Si la somme est supérieure ou égale à 10, on calcule la retenue (15->1)
        sum = sum % 10;    //  chiffre des unités 17 -> 7

        tail = (Node*)malloc(sizeof(Node));
        if (tail == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }

        tail->val = sum;
        tail->next = NULL;

        if (result == NULL) {
            result = tail;  //Le premier nœud devient la tête
        } else {
           prec->next = tail;
        }
       prec = tail;
    }

    return result;
}


int main() {
    int n1, n2;

    // Create the first linked list:
    printf("Enter the number of nodes in the first list: ");
    scanf("%d", &n1);

    Node* list1 = createList(n1);
    printf("First list: \n");
    displayList(list1);

    // Create the second linked list:
    printf("Enter the number of nodes in the second list: ");
    scanf("%d", &n2);

    Node* list2 = createList(n2);
    printf("Second list: \n");
    displayList(list2);

    // Add the two numbers:
    Node* result = addthetwonumbers(list1, list2);

    // Display the result:
    printf("Resultant list: \n");
    displayList(result);


    return 0;
}
