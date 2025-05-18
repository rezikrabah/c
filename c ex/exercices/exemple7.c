#include <stdio.h>

typedef struct Etudiant Etudiant;
struct Etudiant {
    char nom[12];
    char prenom[12];
    int age;
    float tabNotes[5];
    float moyenne;
};

int main() {
    int i, t = 0;
    float moyenne;
    Etudiant etds[3];

    for (i = 0; i < 3; i++) {
        printf("Donner le nom de l'etudiant %d: ", i+1);
        scanf("%s", etds[i].nom);
        printf("Donner le prenom de l'etudiant %d: ", i+1);
        scanf("%s", etds[i].prenom);
        printf("Donner l'age de l'etudiant %d: ", i+1);
        scanf("%d", &etds[i].age);
        printf("Donner les notes de l'etudiant %d: ", i+1);
        for (int j = 0; j < 5; j++) {
            scanf("%f", &etds[i].tabNotes[j]);
            t += etds[i].tabNotes[j];
        }
        etds[i].moyenne = t / 5.0;
    }

    // Calculate average
    moyenne = 0;
    for (i = 0; i < 3; i++) {
        moyenne += etds[i].moyenne;
    }
    moyenne /= 3.0;

    printf("La moyenne generale est : %.2f\n", moyenne);

    return 0;
}
