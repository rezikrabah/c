#include <stdio.h>

//typedef struct {
//    int jour;
//    int mois;
//    int annee;
//} Date;

typedef struct Date Date;
struct Date {
    int jour;
    char mois [12];
    int annee;
};

Date LireDate(void) {
    Date date;
    printf("Entrez le jour: ");
    scanf("%d", &date.jour);
    printf("Entrez le mois: ");
    scanf("%s", date.mois);
    printf("Entrez l'année: ");
    scanf("%d", &date.annee);
    return date;
}

void AfficheDate(Date date) {
    printf("Date: %d,%s,%d\n", date.jour,date.mois,date.annee);

}


