#include "projetc.h"

int main(void)
{
    struct partie *p1=creerPartie();
    affichage3(p1);
    p1->premierJoueurJoue=0;
    setCase(p1,2,1,-1);
    
    
    sauvegardePartie(p1);
    return 0;
}
