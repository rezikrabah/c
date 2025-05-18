#include<stdio.h>
#include<stdlib.h>
struct module{
    char intitule[30];
    int coeffi;
    struct module *modulesuiv;
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

// FONCTION POUR AJOUTER DEBUT

struct module* ajouterdebut(struct module*tete){
struct module* nvmodule=malloc(sizeof(struct module));
printf("\n donner moi intitule:");
scanf("%s",&nvmodule->intitule);
printf("donner moi la coeffi:");
scanf("%d",&nvmodule->coeffi);
nvmodule->modulesuiv=tete;
tete=nvmodule;
return tete;
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
 ptr-> modulesuiv    =   malloc(sizeof(struct module));


    ptr=ptr->modulesuiv;
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
afficher(tete);
ajouterdebut(&tete);

    return 0;
}








