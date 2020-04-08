#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

/*
 * ---------------------------------------------------------------------------
 * Createur : Mikael Juillet
 * But : Faire une bataille navale dans le cadre du cour MA-20.
 * Verssion : travail sur la verssion 1.0 - verssion total 0.9
 * Date : 08.04.2020
 * ---------------------------------------------------------------------------
 */

//ici l'on declare les fonction utiliser pour les utiliser patout.
void menuBase();
void jeux();
void grille();
void inscription();
void connexion();

FILE* Logs = NULL;

// gille de base car nous avons besoin ici pour l'utiliser dans toutes les fonction.
int grilleBase [10][10] ={0};


//================================= MODE grille =====================================================
void grille() {
    fprintf(Logs,"Choix de la grille \n");
    //declaration et initialisation des varriables
    int ligne, col, aleatoire = 0;

    int grille1[10][10] = {
            0,5,0,0,0,1,0,0,0,0,
            0,5,0,0,0,1,0,0,0,0,
            0,0,0,0,0,1,0,0,0,0,
            0,0,0,0,0,1,0,0,0,0,
            0,0,0,0,0,1,0,0,0,0,
            2,2,2,2,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,3,3,3,0,0,0,0,0,
            0,0,0,0,0,0,4,4,4,0,
            0,0,0,0,0,0,0,0,0,0};

    int grille2[10][10] = {
            0,1,0,0,0,3,0,0,0,0,
            0,1,0,0,0,3,0,0,0,0,
            0,1,0,0,0,3,0,0,0,0,
            0,1,0,2,0,0,0,0,0,0,
            0,1,0,2,0,0,0,0,0,0,
            0,0,0,2,0,0,0,0,0,0,
            0,0,0,2,0,0,0,0,0,0,
            0,0,0,0,0,4,4,4,0,0,
            0,0,0,0,0,0,5,5,0,0,
            0,0,0,0,0,0,0,0,0,0};

    int grille3[10][10] = {
            0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0,5,5,0,0,0,0,0,
            0,0,0,0,0,0,0,2,0,0,
            1,1,1,1,1,0,0,2,0,0,
            0,0,0,3,0,0,0,2,0,0,
            0,0,0,3,0,0,0,2,0,0,
            0,0,0,3,0,0,0,0,0,0,
            0,0,0,0,0,4,4,4,0,0,
            0,0,0,0,0,0,0,0,0,0};

    int grille4[10][10] = {
            0,0,4,4,4,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,5,
            0,0,0,0,0,0,0,0,0,5,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,2,
            0,0,0,0,0,0,0,0,0,2,
            0,0,0,0,0,0,0,0,0,2,
            0,0,0,0,0,0,0,0,0,2,
            1,1,1,1,1,0,3,3,3,0};

    int grille5[10][10] = {
            1,1,1,1,1,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,2,0,0,0,0,0,
            0,0,0,0,2,0,0,0,0,0,
            0,0,0,0,2,0,0,0,0,0,
            0,0,0,0,2,0,3,0,0,0,
            0,0,4,0,0,0,3,0,0,0,
            0,0,4,0,0,0,3,0,0,0,
            0,0,4,0,0,0,0,0,0,0,
            0,0,0,0,5,5,0,0,0,0};

    // choix aleatoire d'un chifre pour le choix aléatoire d'une grille.
    srand((unsigned) time(NULL));
    aleatoire = 1 + rand() % 5;

    // choix de la map elle se met dans la grille base
    switch (aleatoire) {
        case 1:
            for (ligne = 0; ligne < 10; ligne++) {
                for (col = 0; col < 10; col++) {
                    grilleBase[ligne][col] = grille1[ligne][col];
                }
            }
            break;
        case 2:
            for (ligne = 0; ligne < 10; ligne++) {
                for (col = 0; col < 10; col++) {
                    grilleBase[ligne][col] = grille2[ligne][col];
                }
            }
            break;
        case 3:
            for (ligne = 0; ligne < 10; ligne++) {
                for (col = 0; col < 10; col++) {
                    grilleBase[ligne][col] = grille3[ligne][col];
                }
            }
            break;
        case 4:
            for (ligne = 0; ligne < 10; ligne++) {
                for (col = 0; col < 10; col++) {
                    grilleBase[ligne][col] = grille4[ligne][col];
                }
            }
            break;
        case 5:
            for (ligne = 0; ligne < 10; ligne++) {
                for (col = 0; col < 10; col++) {
                    grilleBase[ligne][col] = grille5[ligne][col];
                }
            }
            break;
        default:
            for (ligne = 0; ligne < 10; ligne++) {
        for (col = 0; col < 10; col++) {
            grilleBase[ligne][col] = grille5[ligne][col];
        }
    }
            break;
    }
}


//================================= MODE JEUX =====================================================
void jeux(){

    //ici l'on netoye la page
    system("cls");

    //declaration et initialisation des varriables
    int afLigne=0,afCol=0;
    int verChoisi=0,horChoisi=0;
    int gagner=0, coups=0;
    int porteAvion=0,croiseur=0,contreTorpilleur1=0,contreTorpilleur2=0,torpilleur=0;
    char visuel[10][10]={
            '~','~','~','~','~','~','~','~','~','~',
            '~','~','~','~','~','~','~','~','~','~',
            '~','~','~','~','~','~','~','~','~','~',
            '~','~','~','~','~','~','~','~','~','~',
            '~','~','~','~','~','~','~','~','~','~',
            '~','~','~','~','~','~','~','~','~','~',
            '~','~','~','~','~','~','~','~','~','~',
            '~','~','~','~','~','~','~','~','~','~',
            '~','~','~','~','~','~','~','~','~','~',
            '~','~','~','~','~','~','~','~','~','~'};

    system("cls");
    //debut de la boucle qui nous sert à rafrechire la page
    do {

        printf("              Bataille Navale\n\n\n");

        //creation du tabreau graphique avec les numero des colones et des lignes

        printf("   |_1___2___3___4___5___6___7___8___9__10_|\n");

        //Créeation d'une double boucle pour afficher le tableau
        for (afLigne=0; afLigne<10;afLigne++){
            if (afLigne==9){
                printf(" %d",afLigne+1);    //Un if car le 10 prend un caractere de plus
            } else{
                printf("  %d",afLigne +1);
            }
            for (afCol=0; afCol<10;afCol++){
                printf("| %c ",visuel[afLigne][afCol]);
            }
            printf("|\n");
            printf("   |---|---|---|---|---|---|---|---|---|---|\n");
        }
        //fais une ligne dans le fichier logs
        fprintf(Logs,"Affichage du jeux \n");

        //demande des choix à l'utilisteur

        do {

            do {
                printf("\n\nChoisisez une case verticale :");
                scanf("%d", &verChoisi);
                verChoisi -= 1;
            } while (verChoisi > 9||verChoisi<0);

            do {
                printf("Choisisez une case horizontal :");
                scanf("%d", &horChoisi);
                horChoisi -= 1;
            } while (horChoisi > 9||horChoisi<0);

            if (grilleBase[horChoisi][verChoisi] == 9) {
                printf("\nVous avez deja toucher cette case recommencer \n");
            }
        } while (grilleBase[horChoisi][verChoisi] == 9);

        //fais une ligne dans le fichier logs
        fprintf(Logs,"Choix des cases \n");

        //toutes les posibilité de jeux par le joueur (affichage de gagner ou pas, X ou O)
        if (grilleBase[horChoisi][verChoisi] == 0) {
            printf("\nRater");
            grilleBase[horChoisi][verChoisi] = 9;
            visuel[horChoisi][verChoisi] ='O';
            coups++;
        }
        if(grilleBase[horChoisi][verChoisi]==1){
            printf("\ntoucher");
            grilleBase[horChoisi][verChoisi] =9;
            gagner++;
            porteAvion++;
            coups++;
            visuel[horChoisi][verChoisi] ='X';
        }
        if(grilleBase[horChoisi][verChoisi]==2){
            printf("\ntoucher");
            grilleBase[horChoisi][verChoisi] =9;
            gagner++;
            croiseur++;
            coups++;
            visuel[horChoisi][verChoisi] ='X';
        }
        if(grilleBase[horChoisi][verChoisi]==3){
            printf("\ntoucher");
            grilleBase[horChoisi][verChoisi] =9;
            gagner++;
            contreTorpilleur1++;
            coups++;
            visuel[horChoisi][verChoisi] ='X';
        }
        if(grilleBase[horChoisi][verChoisi]==4){
            printf("\ntoucher");
            grilleBase[horChoisi][verChoisi] =9;
            gagner++;
            contreTorpilleur2++;
            coups++;
            visuel[horChoisi][verChoisi] ='X';
        }
        if(grilleBase[horChoisi][verChoisi]==5){
            printf("\ntoucher");
            grilleBase[horChoisi][verChoisi] =9;
            gagner++;
            torpilleur++;
            coups++;
            visuel[horChoisi][verChoisi] ='X';
        }

        //chaque posiblilité de gagner
        if(porteAvion==5){
            printf(" couler");
            porteAvion=0;
        }
        if (croiseur==4){
            printf(" couler");
            croiseur=0;
        }
        if(contreTorpilleur1==3){
            printf(" couler");
            contreTorpilleur1=0;
        }
        if(contreTorpilleur2==3){
            printf(" couler");
            contreTorpilleur2=0;
        }
        if(torpilleur==2){
            printf(" couler");
            torpilleur=0;
        }
        //fais une ligne dans le fichier logs
        fprintf(Logs,"Fin de la partie\n");

        if(gagner==17){
            printf("\ngagner\n");
        }
        Sleep(700);
        system("cls");
    }while(gagner<17);

    //Fin de la partie avec fonction de retour au menu
    //fais une ligne dans le fichier logs
    fprintf(Logs,"\n\nAffichage du résultat de la partie \n");
    system("cls");
    printf("\nVous avez fini la partie avec %d coups\n\n",coups);

    FILE* resutats = NULL;
    resutats = fopen("resutats", "a");
    fprintf(resutats, "Resultats %d \n", coups);
    fclose(resutats);

    system("pause");
    menuBase();


}

//================================= MODE resultat =================================================
void resultat(){

    signed char texte [500];
    //fais une ligne dans le fichier logs
    fprintf(Logs,"Affichage des résultats des joueurs \n");

    //ici l'on netoye la page
    system("cls");

    FILE* resutats = NULL;
    resutats = fopen("resutats", "r");


    printf("Resultat des anciennes parties\n");

    while(fgets(texte, 499, resutats) != NULL){
        printf("%s\n",texte);
    }

    fclose(resutats);

    system("pause");
    menuBase();
}


//================================= MODE Utilisateur ==============================================
void utilisateur() {

    //ici l'on netoye la page
    system("cls");

    //declaration et initialisation des varriables
    int choix;

    //fais une ligne dans le fichier logs
    fprintf(Logs,"Affichage du menu utilisateur \n");

    printf("utilisateur\n\n");
    printf("1 : Me connecter\n");
    printf("2 : M'inscrire\n");
    printf("3 : Retour\n");

    do{
    printf("Que voulez-vous faire ?");
    scanf("%d", &choix);

    }while (choix <1 || choix >3);


    switch (choix) {
        case 1:
            connexion();
            break;
        case 2:
            inscription();
            break;
        case 3:
            menuBase();
        break;
    }



    system("pause");
    menuBase();
}


//================================= inscription =====================================================
void inscription (){

    signed char utilisateur [100];
    FILE* fichier = NULL;
    do {
        //ici l'on netoye la page
        system("cls");
        printf("M'inscrire\n\n");
        printf("Choisisez votre nom d'utilisateur : ");
        scanf("%s", utilisateur);
        fichier = fopen(utilisateur, "r+");
    }while(fichier != NULL);
    fichier = fopen(utilisateur, "w");
    //fais une ligne dans le fichier logs
    fprintf(Logs,"Création d'un utilisateur \n");

    fclose(fichier);
}


//================================= connexion =====================================================
void connexion() {

    signed char utilisateur[100];
    FILE *fichier = NULL;
    do {
        //ici l'on netoye la page
        system("cls");
        printf("M'inscrire\n\n");
        printf("Choisisez votre nom d'utilisateur : ");
        scanf("%s", utilisateur);
        fichier = fopen(utilisateur, "r+");
    } while (fichier == NULL);
    //fais une ligne dans le fichier logs
    fprintf(Logs, "Connextion a un utilisateur\n");

}

//================================= MODE AIDE =====================================================
void modeAide(){

    //fais une ligne dans le fichier logs
    fprintf(Logs,"Affichage du mode aide \n");

    //ici l'on netoye la page
    system("cls");

    //creation du mode aide qui afficher les regle de base du programme
    printf("Mode Aide\n\n");
    printf("Regle :\n");
    printf("Une grille de 10 par 10, faite par le programme a placer les bateau sur une grille vous devez les retrouver.\n");
    printf("Il vous suffira d'introduire une les cordonees du point que vous voullez toucher et le logiciel vous dira si \n");
    printf("vous avez toucher, ratter ou couler un bateau.\n\n");

    printf("Toucher : signifie que vous avez toucher une partie du bateau mais il n'est pas encore couler.\n");
    printf("Rater : signifie que vous avez viser dans l'eau il faut donc retenter sa chance.");
    printf("Couler : signifie que vous avez toucher toutes les partie du bateau il est donc hors jeux.\n\n");

    printf("Bateau :\n");
    printf("Il y a 5 bateau\n");
    printf("1 porte-avion (il s'etale sur 5 cases)\n");
    printf("1 croiseur (il s'etale sur 4 cases)\n");
    printf("2 contre-torpilleurs (il s'etale sur 3 cases)\n");
    printf("1 torpilleur (il s'etale sur 2 cases)\n\n\n");

    system("pause");
    menuBase();

}


//================================= MENU BASE =====================================================
void menuBase(){

    //fais une ligne dans le fichier logs
    fprintf(Logs,"Affichage du menu \n");

    //ici l'on netoye la page
    system("cls");

    // Mise en place de la page titre dans une fonction pour la reutiliser.
    int choix=0;    //initioalisation de la variable.
    printf("Bataille Navale\n\n");

    printf("1 : Jouer\n");
    printf("2 : Utilisateur\n");
    printf("3 : Resultat\n");
    printf("4 : Aide\n");
    printf("5 : Quitter\n");

    do {
        //Chois vers les différents mode
        printf("Choisissez une option :");
        scanf("%d", &choix);
    }while (choix <0 || choix >5);

    switch(choix){
        case 1:grille();
                jeux();
            break;
        case 2: utilisateur();
            break;
        case 3: resultat();
            break;
        case 4:modeAide() ;
            break;
        case 5: system("exit");
            break;

    }
}

//================================= MAIN =====================================================
int main(){

    Logs = fopen("Logs", "a");
    fprintf(Logs,"Ouverture du programme \n");

    //l'on choisis le nom de la console
    SetConsoleTitle("Bataille Navale");

    //l'on choissi de metre en premier la fonction menuBase
    menuBase();

    fprintf(Logs, "Fermeture du programme \n\n");
    fclose(Logs);
    return 0;
}