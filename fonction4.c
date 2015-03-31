#include "couleursTerminal.h"
#include "projetc.h"

int sauvegardePartie(struct partie *p) {
    FILE *f=NULL;
    int i;
    f=fopen("sauvegarde.txt","wt");
    if(f==NULL){
        printf("Erreur de fopen \n");
        return 0;
    }
    fprintf(f,"%s",p->nomJ1);
    fprintf(f,"%s",p->nomJ2);
    fprintf(f,"%d",p->premierJoueurJoue);
    fprintf(f,"%p",p->damier);
    fclose(f);
    return 1;
}


int chargementPartie(struct partie *p) {
    FILE *f=NULL;
    int i;
    char ch[]="";
    f=fopen("sauvegarde.txt","rt");
    if(f==NULL){
        printf("Erreur de fopen \n");
        return 0;
    }
    fscanf(f,"%s\n",ch);
    printf("ch: %s \n",ch);
    while(!feof(f)){
        fscanf(f,"%s",p->nomJ2);
        fscanf(f,"%d",p->premierJoueurJoue);
        fscanf(f,"%p",p->damier);
    }
    fclose(f);
    return 1;
}

int menu(struct partie *p){
    
}