#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int score_total = 0;  // Variable globale pour le score total
char nom_joueur[100]; // Variable pour le nom du joueur

// Fonction pour sauvegarder le score dans un fichier
void sauvegarder_score() {
	FILE *file;
	time_t now;
	struct tm *tm_info;
	char date_heure[100];

	// Obtenir la date et l'heure actuelle
	time(&now);
	tm_info = localtime(&now);
	strftime(date_heure, 100, "%Y-%m-%d %H:%M:%S", tm_info);

	// Ouvrir le fichier pour ajouter le score
	file = fopen("scores.txt", "a");
	if (file != NULL) {
		fprintf(file, "Nom: %s, Date: %s, Score: %d\n", nom_joueur, date_heure, score_total);
		fclose(file);
	} else {
		printf("Erreur lors de l'enregistrement du score.\n");
	}
}

// Fonction pour charger le score depuis un fichier
void charger_score() {
    FILE *file;
    char ligne[200];
    int trouve = 0;
    char nom_lu[200];
    int score_lu;

    // Demander a l'utilisateur son nom
    printf("Entrez votre nom: ");
    scanf("%s", nom_joueur);

    // Ouvrir le fichier pour lire les scores
    file = fopen("scores.txt", "r");
    if (file != NULL) {
        while (fgets(ligne, sizeof(ligne), file)) {
            sscanf(ligne, "Nom: %[^,], Date: %*[^,], Score: %d", nom_lu, &score_lu);
            if(strcmp(nom_lu,nom_joueur)==0){
                score_total= score_lu;
                trouve = 1;
            }
        }
    }
    if (trouve) {
        printf("Bienvenue %s votre score precedent etait: %d\n", nom_joueur, score_total);
    }
    else {
        printf("Bienvenue %s, vous n'avez pas de score precedent.\n", nom_joueur);
    }
    fclose(file);
}

// Fonction pour ajouter un score au total
void ajouter_score(int points) {
    score_total += points;
    sauvegarder_score();  // Sauvegarder le score dans un fichier dès qu'il est modifié
}

void addition() {
    int a, b, reponse, essais = 0;
    printf("Addition\n");
    a = rand() % 101;
    b = rand() % 101;
    printf("%d + %d = ?\n", a, b);
    printf("Entrez le resultat\n");

    while (essais < 3) {
        scanf("%d", &reponse);
        printf("Vous avez entre %d\n", reponse);
        if (reponse == a + b) {
            if (essais == 0) {
                ajouter_score(10);  // 10 points pour le premier essai
            } else if (essais == 1) {
                ajouter_score(5);  // 5 points pour le deuxième essai
            } else {
                ajouter_score(1);  // 1 point pour le troisième essai
            }
            printf("Bravo\n");
            return;
        } else {
            printf("Mauvaise reponse :/\n");
            essais++;
            if (essais < 3) {
                printf("Essayez encore (essai %d sur 3)\n", essais + 1);
            }
        }
    }
    printf("Perdu ! La bonne reponse était %d\n", a + b);
}

void soustraction() {
    int a, b, reponse, essais = 0;
    printf("Soustraction\n");
    a = rand() % 101;
    do {
        b = rand() % 101;
    } while (a < b);
    printf("%d - %d = ?\n", a, b);
    printf("Entrez le resultat\n");

    while (essais < 3) {
        scanf("%d", &reponse);
        printf("Vous avez entre %d\n", reponse);
        if (reponse == a - b) {
            if (essais == 0) {
                ajouter_score(10);
            } else if (essais == 1) {
                ajouter_score(5);
            } else {
                ajouter_score(1);
            }
            printf("Bravo\n");
            return;
        } else {
            printf("Mauvaise reponse :/\n");
            essais++;
            if (essais < 3) {
                printf("Essayez encore (essai %d sur 3)\n", essais + 1);
            }
        }
    }
    printf("Perdu ! La bonne reponse était %d\n", a - b);
}

void multiplication() {
    int a, b, reponse, essais = 0;
    printf("Multiplication\n");
    a = rand() % 11;
    b = rand() % 11;
    printf("%d * %d = ?\n", a, b);
    printf("Entrez le resultat\n");

    while (essais < 3) {
        scanf("%d", &reponse);
        printf("Vous avez entre %d\n", reponse);
        if (reponse == a * b) {
            if (essais == 0) {
                ajouter_score(10);
            } else if (essais == 1) {
                ajouter_score(5);
            } else {
                ajouter_score(1);
            }
            printf("Bravo\n");
            return;
        } else {
            printf("Mauvaise reponse :/\n");
            essais++;
            if (essais < 3) {
                printf("Essayez encore (essai %d sur 3)\n", essais + 1);
            }
        }
    }
    printf("Perdu ! La bonne reponse était %d\n", a * b);
}

void table_multiplication() {
    int choix_table, i, choix_d, reponse, essais = 0;
    printf("Tables de multiplication\n");
    printf("Choix de la table entre 1 et 10\n");
    scanf("%d", &choix_table);
    while (choix_table < 1 || choix_table > 10) {
        printf("Nombre hors plage. Veuillez ressayer.\n");
        scanf("%d", &choix_table);
    }
    for (i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", choix_table, i, choix_table * i);
    }
    printf("Voulez-vous entrainer ? 0/1 \n");
    scanf("%d", &choix_d);
    if (choix_d == 1) {
        for (i = 1; i <= 10; i++) {
            printf("%d * %d = ?\n", choix_table, i);
            printf("Entrez le resultat\n");

            while (essais < 3) {
                scanf("%d", &reponse);
                printf("Vous avez entre %d\n", reponse);
                if (reponse == choix_table * i) {
                    if (essais == 0) {
                        ajouter_score(10);
                    } else if (essais == 1) {
                        ajouter_score(5);
                    } else {
                        ajouter_score(1);
                    }
                    printf("Bravo\n");
                    break;
                } else {
                    printf("Mauvaise reponse :/\n");
                    essais++;
                    if (essais < 3) {
                        printf("Essayez encore (essai %d sur 3)\n", essais + 1);
                    }
                }
            }
            essais = 0;  // Réinitialiser les essais après chaque question
        }
    }
}

void division() {
    int a, b, quotient, reste, essais = 0;
    printf("Division\n");
    a = rand() % 101;   // permet de limiter les choix du nombre aléatoire entre 0 et 100
    do {
        b = rand() % 10 + 1;
    } while (a < b);
    printf("%d / %d = ?\n", a, b);
    printf("Entrez le quotient\n");

    while (essais < 3) {
        scanf("%d", &quotient);
        printf("Vous avez entre %d en quotient\n", quotient);
        printf("Entrez le reste\n");
        scanf("%d", &reste);
        printf("Vous avez entre %d en reste\n", reste);
        if (quotient == a / b && reste == a % b) {
            if (essais == 0) {
                ajouter_score(10);
            } else if (essais == 1) {
                ajouter_score(5);
            } else {
                ajouter_score(1);
            }
            printf("Bravo\n");
            return;
        } else {
            printf("Mauvaise reponse\n");
            essais++;
            if (essais < 3) {
                printf("Essayez encore (essai %d sur 3)\n", essais + 1);
            }
        }
    }
    printf("Perdu ! La bonne reponse était %d quotient et %d reste\n", a / b, a % b);
}

int main() {
    int choix;
    srand(time(NULL));

    // Charger le score de l'utilisateur dès le début
    charger_score();

    printf("+-----------------------------------+\n");
    printf("|1 : Addition                       |\n");
    printf("|2 : Soustraction                   |\n");
    printf("|3 : Multiplication                 |\n");
    printf("|4 : Tables des multiplications     |\n");
    printf("|5 : Division                       |\n");
    printf("|0 : Sortir du jeu                  |\n");
    printf("+-----------------------------------+\n");
    printf("Quel est votre choix ?\n");

    scanf("%d", &choix);

    while (choix != 0) {
        while (choix < 0 || choix > 5) {
            printf("Nombre hors plage. Veuillez ressayer.\n");
            printf("Quel est votre choix ?\n");
            scanf("%d", &choix);
        }

        switch (choix) {
            case 1:
                addition();
                break;
            case 2:
                soustraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                table_multiplication();
                break;
            case 5:
                division();
                break;
            default:
                printf("Option non valide.\n");
        }

        printf("+-----------------------------------+\n");
        printf("|1 : Addition                       |\n");
        printf("|2 : Soustraction                   |\n");
        printf("|3 : Multiplication                 |\n");
        printf("|4 : Tables des multiplications     |\n");
        printf("|5 : Division                       |\n");
        printf("|0 : Sortir du jeu                  |\n");
        printf("+-----------------------------------+\n");
        printf("Quel est votre choix ?\n");
        scanf("%d", &choix);
    }

    printf("Merci de votre visite\n");
    printf("Votre score total est : %d\n", score_total);  // Affichage du score total
    return 0;
}
