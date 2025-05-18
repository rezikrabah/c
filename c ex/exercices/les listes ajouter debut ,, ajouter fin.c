#include <stdio.h>
#include <stdlib.h>



typedef struct Liste Liste;

struct Liste {
    int valeur;
    Liste* suivant;
};

void ajouterDebut (Liste **tete, int val){
    Liste *element = malloc(sizeof(Liste));
    element->valeur = val;
    element->suivant = *tete;
    *tete = element;
}


void ajouterFin (Liste **tete, int val){

    Liste *element = malloc(sizeof(Liste));
    element->valeur = val;
    element->suivant = NULL;

    Liste*  p = *tete;

    if(p == NULL){
        *tete = element;
    }

    else {
    while (p->suivant != NULL){
        p = p->suivant;
    }

        p->suivant = element;
    }}


void ajouterMilieux (Liste **tete, int val, int pos){

    Liste *element = malloc(sizeof(Liste));
    element->valeur = val;

    Liste* p = *tete;

    if(pos == 1){
        element->suivant = *tete;
        *tete = element;
    }

    else {
        pos = pos - 1;
    while ((p!= NULL) && (pos > 1)){
        p = p->suivant;
        pos = pos - 1;
    }
        if (p == NULL){
            printf("ereure : la position n'existe pas \n");
        }
        else {
            element->suivant = p->suivant;
            p->suivant = element;}
    }

}



void afficherList (Liste **tete){

    Liste *p = *tete;
    printf ("Debut -> ");
    while (p != NULL){
        printf (" %d -> ", p->valeur);
        p = p->suivant;
    }
}



int main(int argc, const char * argv[]) {

    Liste* tete = NULL;

    int v,i,p;

    for (i=0 ; i <5 ; i++){
        printf("donner la valeur : ");
        scanf("%d", &v);
//        ajouterDebut(&tete, v);
        ajouterFin(&tete, v);
    }


    afficherList(&tete);
       printf("donner la valeur a ajouter : ");
       scanf("%d", &v);
       printf("donner la position : ");
       scanf("%d", &p);
       ajouterMilieux(&tete, v, p);
       afficherList(&tete);
}
