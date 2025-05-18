#include <stdio.h>
#include <stdlib.h>

struct noeud {
    int x;
    struct noeud* noeudsuiv;
};

// FONCTION POUR AFFICHER LA LISTE
void afficher(struct noeud* tete) {
    if (tete == NULL) {
        printf("la liste est vide\n");
    } else {
        printf("voici la liste :");
         printf(" debut--->");
        while (tete != NULL) {

            printf("x ->>>>> %d ", tete->x);
            tete = tete->noeudsuiv;
        }
        printf("NULL");
    }
}

// FOMCTION POUR AJOUTER FIN
struct noeud* ajouterfin(struct noeud* tete, int x) {
    struct noeud* nvnoeud = malloc(sizeof(struct noeud));
    nvnoeud->x = x;
    nvnoeud->noeudsuiv = NULL; // Pointer to NULL as it's the last node

    if (tete == NULL) {
        // List is empty
        tete = nvnoeud;
    } else {
        // List is not empty
        struct noeud* ptr = tete;
        while (ptr->noeudsuiv != NULL) {
            ptr = ptr->noeudsuiv;
        }
        ptr->noeudsuiv = nvnoeud;
    }

    return tete;
}


int main() {
    struct noeud* tete = NULL;
    int i;
    for (i = 0; i < 10; i++) {
        tete = ajouterfin(tete, i);


    }
     afficher(tete);
    return 0;
}
