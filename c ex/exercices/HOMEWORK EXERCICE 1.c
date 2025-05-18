#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

// creation  :
Node * CreateL1(int n){
    Node *head = NULL ;
    Node*tail=NULL;
    int x;
    for ( int i =0; i < n ; i++){

        Node * new_node  = (Node*)malloc(sizeof(Node));
        if (new_node == NULL) {
         perror("Failed to allocate memory");
         exit(EXIT_FAILURE);
        }
        printf("enter the value of node %d:", i+1);
        scanf("%d",&x);
        new_node->val =x;
        new_node->next = NULL;
        if(head==NULL){}
        head=new_node;
        tail=new_node;

    }

    return head;
}
    // creation  :
Node * CreateL1(int n){
    Node *head = NULL ;
    Node*tail=NULL;
    int y;
    for ( int i =0; i < n ; i++){

        Node * new_node  = (Node*)malloc(sizeof(Node));
        if (new_node == NULL) {
         perror("Failed to allocate memory");
         exit(EXIT_FAILURE);
        }
        printf("enter the value of node %d:", i+1);
        scanf("%d",&y);
        new_node->val =y;
        new_node->next = NULL;
        if(head==NULL){}
        head=new_node;
        tail=new_node;

    }





// fonction pour afficher la liste:
void afficher(struct Node*head){

if (head==NULL){
    printf("la liste est vide");
} else{
    printf("voici la listes :\n");
    while(head!=NULL){
            printf("debut--->");

    printf("val: %d\n");

    }
    printf("NULL ");
 }
}







int main() {
int n ;
    printf("Enter the number sof nodes in liste 1 : ");
    scanf("%d",&n);
    while(n>0 || n<10){
    Node *liste1 = CreateL1( n);
    printf("liste1:\n ");
    }


 printf("Enter the numbers of nodes in liste2 : ");
    scanf("%d",&n);
    while(n>0 || n<10){
    Node *liste2 = CreateL2(n);
    printf("liste2:\n ");
    }
}



