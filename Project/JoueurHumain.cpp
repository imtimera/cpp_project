
#include "JoueurHumain.h"
#include "Grille.h"

JoueurHumain::JoueurHumain():Joueur() {

}
JoueurHumain::JoueurHumain(string nom):Joueur(nom) {
}

JoueurHumain::JoueurHumain(const JoueurHumain& orig):Joueur(orig) {
}

int JoueurHumain::generePos(){
    int i;
    cin >>i;                        
    /* 1 --> Gauche ~~ 2 --> Bas    ^
     * 3 --> Droite ~~ 5 --> Haut <   >
     *                              v
     */
      while (i<1 || i>5 || i==4 ){
        cout << "Direction invalide: reesayer ? ";
        cin >> i;
      }
    return  i;
}
void JoueurHumain::Jouer(Grille *Gt){
    while (!Gt->isOver()){
        int dir;
        Gt->affiche();
        cout << "\n Jouer une direction ? ";
        dir=generePos();        
        while (Gt->deplacer(dir)==false){
            cout << " Jouer une direction ? ";
            dir=generePos();        
        }
    }
    
}

JoueurHumain::~JoueurHumain() {
}

