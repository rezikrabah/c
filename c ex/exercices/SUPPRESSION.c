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
        printf("voici la liste :\n");
        printf("tete--->");
        while (tete != NULL) {

            printf("->(x =%d)", tete->x);
            tete = tete->noeudsuiv;
        }
        printf("->NULL");
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

// FONCTION POUR SUPPRESSION
void supprimernoeud(struct noeud* tete, int v) {
    struct noeud* precedent = NULL;
    struct noeud* courant = tete;

    if (tete != NULL && tete->x == v) {
        struct noeud* ptr = tete;
        tete = tete->noeudsuiv;
        free(ptr);
    } else {
        while (courant != NULL) {
            if (courant->x == v) {
                precedent->noeudsuiv = courant->noeudsuiv;
                free(courant);
                break;
            } else {
                courant = courant->noeudsuiv;
                if (precedent == NULL) {
                    precedent = tete;
                } else {
                    precedent = precedent->noeudsuiv;
                }
            }
        }

    }
}

int main() {
    struct noeud* tete = NULL;
    int i;
    for (i = 0; i < 10; i++) {
        tete = ajouterfin(tete, i);
supprimernoeud(tete, 5);
    }
    afficher(tete);

    return 0;
}
