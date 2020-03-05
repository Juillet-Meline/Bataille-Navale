#include <stdio.h>
#include <windows.h>

/*
 * Createur : Meline Juillet
 * But : Faire une bataille navale dans le cadre du cour MA-20.
 * Verssion : 0.1
 * Date : 05.03.2020
 */
void menuBase();

void modeAide(){

    //initialisation de la variable retour il vas nous permettre d'aller au menu
    int retour=0, menu;

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
    printf("Il y a 4 bateau\n");
    printf("1 porte-avion (il s'etale sur 5 cases)\n");
    printf("1 croiseur (il s'etale sur 4 cases)\n");
    printf("2 contre-torpilleurs (il s'etale sur 3 cases)\n");
    printf("1 torpilleur (il s'etale sur 2 cases)\n\n\n");

    printf("Tapper sur 1 pour revenir au menu");
    scanf("%d",&retour);
    if (retour=1){
        menuBase();
    }

}
void menuBase(){
// Mise en place de la page titre dans une fonction pour la reutiliser.
    int choix=0;    //initioalisation de la variable.
    printf("Bataille Navale\n\n");

    printf("1 : Jouer\n");
    printf("2 : Utilisateur\n");
    printf("3 : Resultat\n");
    printf("4 : Aide\n");
    printf("5 : Quitter\n");

    printf("Choisissez une option :");
    scanf("%d",&choix);

    switch(choix){
        case 1: ;
            break;
        case 2: ;
            break;
        case 3: ;
            break;
        case 4: modeAide() ;
            break;
        case 5:;
    }
}


int main() {
    //Initialisation des varriables
    int menuChoisis =0, aide=0;
    /*
     * L'on met la sortie de menuBase dans menuChoisis pour l'utiliser dans le switch
     * Pour pouvoir faire le choix du menu
    */
    menuBase();


    return 0;
}