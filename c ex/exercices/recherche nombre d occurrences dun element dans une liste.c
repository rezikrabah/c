#include<stdio.h>
#include<stdlib.h>
struct module{
    char intitule[30];
    int coeffi;
    struct module*modulesuiv;
};
//FONCTION POUR CRREE UNE LISTE
struct module*initialiser(struct module*t){
    t=malloc(sizeof(struct module));
    struct module*ptr=t;
    char reponse;
    do{
printf("donner moi le nom du module :");
scanf("%s",&ptr->intitule);
printf("donner moi la coeffi:\n");
scanf("%d",&ptr->coeffi);
printf("do u want to add new course (y/n)\n");
reponse=getche();
if(reponse=='y'|| reponse=='Y'){
 ptr-> modulesuiv    =   malloc(sizeof(struct module)); // y5rj sahm mn ptr module suiv yru7 ll case jdida


    ptr=ptr->modulesuiv; //bach navonsi ptr li moraha ywli ypwanti 3la li morah
}else{
    ptr->modulesuiv=NULL;
}
  }  while(reponse=='y'|| reponse=='Y');
  return t;
}
//AFFICHAGE
void afficher(struct module*tete){

if (tete==NULL){
    printf("la liste est vide");
} else{
    printf("voici la listes des modules\n");
     printf("\n debut---> \n ");
    while(tete!=NULL){

            printf("intitule:   %s\n",tete->intitule);
    printf("coeffi: %d\n",tete->coeffi);
    tete=tete->modulesuiv;
    }
    printf("------.>>>>> NULL ");
 }
}

//fonction pour calculer nombre d'occurrences dun element
int nombredoccurrence(struct module*tete, char nommodule[30]){
    int nbroccurrences=0;
    struct module*ptr=tete;
    while(ptr!=NULL){
    if(strcmp(ptr->intitule,nommodule)==0)
        nbroccurrences++;
    ptr=ptr->modulesuiv;
}
return nbroccurrences;


}






int main(){
struct module*tete=NULL;
    tete=initialiser(tete);

    afficher (tete);
   char nommodule[30]="algo";
   printf("\n le nombre d occurrences de %s est : %d",nommodule,nombredoccurrence(tete,nommodule));
}
