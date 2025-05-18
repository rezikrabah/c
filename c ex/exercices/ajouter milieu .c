#include<stdio.h>
#include<stdlib.h>
struct module {
    int coeffi;
    char intitule[30];
    struct module*modulesuiv;
};


// FONCTION POUR AFFICHER LA LISTE
    void afficher(struct module*tete){

if (tete==NULL){
    printf("la liste est vide");
} else{
    printf("voici la listes des modules\n");
    while(tete!=NULL){
            printf("debut--->");
            printf("intitule:   %s\n",tete->intitule);
    printf("coeffi: %d\n",tete->coeffi);
    tete=tete->modulesuiv;
    }
    printf("NULL ");
 }
}

    // PROCEDURE POUR AJOUTER MILIEU
    void ajouterMilieu(struct module*tete , char nommodule[30]){
        if(tete==NULL) printf("la liste est vide");
    else{
        struct module*ptr=tete;
        while (ptr!=NULL){
                if(strcmp(ptr->intitule , nommodule)==0){ // STRCMP FONCTION POUR COMPARE ONTRE 2 CHAR IF == 0 THEN TRUE

                struct module*nvmodule=malloc(sizeof(struct module));
        printf("\n -----> saisir les information du nv module -----. \n");
        printf("intitule :");
        scanf("%s",&nvmodule->intitule);

    printf("coeffi :");
        scanf("%d",&nvmodule->coeffi);
    nvmodule->modulesuiv=ptr->modulesuiv;
    ptr->modulesuiv=nvmodule;
ptr=NULL; // pour quitter la boucle
                }else ptr=ptr->modulesuiv;


        }

    }
}



int main(){
    char reponse;
    char x;
struct module *tete =NULL;
tete = malloc(sizeof(struct module));
struct module *ptr =tete ;
do{
printf("\ndonner moi le nom du module :\n");
scanf("%s",&ptr->intitule);
printf("donner moi la coeffi:\n");
scanf("%d",&ptr->coeffi);
printf("\n do u want to add new course (y/n)\n");
reponse=getche();
if(reponse=='y'|| reponse=='Y'){
 ptr-> modulesuiv    =   malloc(sizeof(struct module)); // y5rj sahm mn ptr module suiv yru7 ll case jdida


    ptr=ptr->modulesuiv; //bach navonsi ptr li moraha ywli ypwanti 3la li morah
}else{
    ptr->modulesuiv=NULL;
}
  }  while(reponse=='y'|| reponse=='Y');

printf("\n------------voici la chaine:----------------\n");
printf ("Debut -> ");
ptr=tete;
while(ptr!=NULL){
        printf("-intitule -> %s",ptr->intitule);
printf("-coeffi %d -> ",ptr->coeffi);

ptr=ptr->modulesuiv;
}
printf("NULL ");
ajouterMilieu(tete,"opm");
  afficher(tete);


    return 0;
}
