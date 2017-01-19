#ifndef GRILLE_2048_H
#define GRILLE_2048_H

#include "Grille.h"
class Grille_2048:  public Grille {
/*_______________
 |  4       2    |
 |               |
 |               |
 |               |
 |   32          |
 |       8       |
 |_______________|

 */
 private:
    int valMax;
    void Init() override;
    void RotationHoraire();
    void Rotation(int i);
    bool deplacerDroite();
    int DernierK(int i, int j);
    bool noElement(int i,int j, int k);
    bool deplacable();
    Case* PremierCaseDispo(int i, int j);
    virtual void GenereAlea();
    virtual void fusion(int i, int b);
    int interpreteDir(int dir);
     
 public:
    Grille_2048(Joueur & j);
    Grille_2048(int n,Joueur & j);
    Grille_2048(const Grille_2048& orig);
    int getVal();
    bool isOver();
    virtual ~Grille_2048();
    
    
protected:  
    bool* Cdeplacable;
    void setVal(int v);
    bool deplacer(int dir);
    
    
    

};

#endif /* GRILLE_2048_H */

