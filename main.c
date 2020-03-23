#include <stdio.h>
#include <windows.h>

/*
 * ---------------------------------------------------------------------------
 * Createur : Mikael Juillet
 * But : Faire une bataille navale dans le cadre du cour MA-20.
 * Verssion : travail sur la verssion 1.0 - verssion total 0.6
 * Date : 23.03.2020
 * ---------------------------------------------------------------------------
 */

//ici l'on declare les fonction utiliser pour les utiliser patout.
void menuBase();
void jeux();
void grille();

int grilleBase[10][10] ={0};

//================================= MODE grille =====================================================
void grille(); {

int grille1 [10][10] = {
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
    int grille [10][10];
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

            if (grille[horChoisi][verChoisi] == 9) {
                printf("\nVous avez deja toucher cette case recommencer \n");
            }
        } while (grille[horChoisi][verChoisi] == 9);

        //toutes les posibilité de jeux par le joueur (affichage de gagner ou pas, X ou O)
        if (grille[horChoisi][verChoisi] == 0) {
            printf("\nRater");
            grille[horChoisi][verChoisi] = 9;
            visuel[horChoisi][verChoisi] ='O';
            coups++;
        }
        if(grille[horChoisi][verChoisi]==1){
            printf("\ntoucher");
            grille[horChoisi][verChoisi] =9;
            gagner++;
            porteAvion++;
            coups++;
            visuel[horChoisi][verChoisi] ='X';
        }
        if(grille[horChoisi][verChoisi]==2){
            printf("\ntoucher");
            grille[horChoisi][verChoisi] =9;
            gagner++;
            croiseur++;
            coups++;
            visuel[horChoisi][verChoisi] ='X';
        }
        if(grille[horChoisi][verChoisi]==3){
            printf("\ntoucher");
            grille[horChoisi][verChoisi] =9;
            gagner++;
            contreTorpilleur1++;
            coups++;
            visuel[horChoisi][verChoisi] ='X';
        }
        if(grille[horChoisi][verChoisi]==4){
            printf("\ntoucher");
            grille[horChoisi][verChoisi] =9;
            gagner++;
            contreTorpilleur2++;
            coups++;
            visuel[horChoisi][verChoisi] ='X';
        }
        if(grille[horChoisi][verChoisi]==5){
            printf("\ntoucher");
            grille[horChoisi][verChoisi] =9;
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
        if(gagner==17){
            printf("gagner");
        }
        Sleep(700);
        system("cls");
    }while(gagner<17);

    //Fin de la partie avec fonction de retour au menu 
    system("cls");
    printf("\nVous avez fini la partie avec %d coups\n\n",coups);
    system("pause");
    menuBase();


}
//================================= MODE AIDE =====================================================
void modeAide(){

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

    //ici l'on netoye la page
    system("cls");

    // Mise en place de la page titre dans une fonction pour la reutiliser.
    int choix=0;    //initioalisation de la variable.
    printf("Bataille Navale\n\n");

    printf("1 : Jouer\n");
    printf("2 : Aide\n");
    printf("3 : Quitter\n");

    //Chois vers les différents mode
    printf("Choisissez une option :");
    scanf("%d",&choix);

    switch(choix){
        case 1:jeux() ;
            break;
        case 2:modeAide() ;
            break;
        case 3: system("exit");
    }
}

//================================= MAIN =====================================================
int main() {

    //l'on choisis le nom de la console
    SetConsoleTitle("Bataille Navale");

    //l'on choissi de metre en premier la fonction menuBase
    menuBase();


    return 0;
}