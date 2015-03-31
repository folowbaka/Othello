#include "couleursTerminal.h"
#include "projetc.h"

int saisieJoueur(int *ligne, int *colonne) {
    char ch[2]="";
    char l[3]="";
    printf("A----Abandonner\nM----Menu\nS--Saisir une case:\n");
    scanf("%s",ch);
    if(ch[0]=='A')
        return -2;
    else if(ch[0]=='M')
        return -1;
    else if(ch[0]=='S')
	{
        printf("Saisir la lettre correspondant a la ligne suivi du chiffre correpondant à la colonne :\n");
        scanf("%s",l);
        if(l[0]>='a'  && l[0]<='h' && l[1]<='8' && l[1]>='1'  )
		{
			*ligne=l[0]-'a';
			*colonne=l[1]-'1';
			return 1;
		}
        else
		{
            return 0;
		}
    }
    else
        return 0;
}

int tourJoueur(struct partie *p){
    int ligne,colonne,saisie=0;
    affichage3(p);
    
    if(p->premierJoueurJoue==1)
        printf("Tour de %s (blanc) \n",p->nomJ1);
    else
        printf("Tour de %s (noir) \n",p->nomJ2);
    
    if(joueurPeutJouer(p))
    {
        do{
            saisie=saisieJoueur(&ligne,&colonne);
        }while(saisie==0 || (coupValide(p,ligne,colonne)==0 && saisie==1));
        
        if(saisie==-2 || saisie==-1)
        {
            return saisie;
        }
        else{
            mouvement(p,ligne,colonne);
            changementJoueur(p);
            return 1;
        }
    }
    else{
        changementJoueur(p);
        return 0;
    }
}

int gagnant(struct partie *p){
    int i,noir=0,blanc=0;
    
    
    for(i=0;i<NB_CASES;i++){
        if(p->damier[i]==-1)
            blanc++;
        else if(p->damier[i]==1)
            noir++;
    }
    if(noir>blanc){
        printf("Les noirs l'emportent avec %d sur %d",noir,blanc);
        return 1;
    }
    else if(blanc>noir){
        printf("Les noirs l'emportent avec %d sur %d",blanc,noir);
        return -1;
    }
    else
    {
        printf("Egalite !");
        return 0;
    }
    
}

int finPartie (struct partie *p){
	int a=0;
    a=a+joueurPeutJouer(p);
    changementJoueur(p);
    a=a+joueurPeutJouer(p);
    changementJoueur(p);
    
    if(a)
        return 0;
    else
        return 1;
    
}

int jouerPartie(struct partie *p){
    int tour=0,end=0;
    do{
        tour=tourJoueur(p);
        end=finPartie(p);
    }while(end!=1 && tour!=-2 && tour!=-1);
    if(tour!=-2 && tour!=-1)
        gagnant(p);
    if(tour==-1)
        return 0;
    else
        return 1;
    
}
