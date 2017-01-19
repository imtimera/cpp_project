#include <iostream>
#include <fstream>
#include "JoueurHumain.h"
#include "JoueurRobot.h"
#include "Grille_Taquin.h"
#include "Grille_2048_VarN.h"
#include "Grille_2048_VarT.h"
#include "Grille.h"
#include <ctime>
#include <valarray>

/**
 * Choisir le jeu à executer 
 * 1--> Taquin
 * 2 --> 2048 ?variante? 1?2?3?
 * _ --> choix incorrect l'utilisateur est prier de recommencer
 * @return 
 */
#define objectif 2048

int ChoixJeux() {
    int choixJeu = 0;
    cout << "choisir votre Jeu" << endl << "Taquin --> 1" << endl << "2048 --> 2" << endl;
    do {
        cin >>choixJeu;
        if (choixJeu == 1)
            cout << "vous avez choisi Taquin comme jeu" << endl;
        else if (choixJeu == 2)
            cout << "vous avez choisi 2048 comme jeu" << endl;
        else
            cout << "Choix incorrect" << endl;
    } while (choixJeu != 1 && choixJeu != 2);
    return choixJeu;
}

/*
 **On choisit le joueur qui doit jouer la partie du jeu
 * NB : seul un joueur joue toute une partie du jeu
 * Nous ne sommes pas en presence de jeu de competition
 */
int ChoixJoueur() {
    int choixJoueur = 0;
    string nom;
    cout << "choisir Joueur" << endl << "Humain --> 1" << endl << "Robot --> 2" << endl;
    do {
        cin >>choixJoueur;
        if (choixJoueur == 1)
            cout << "vous avez choisi le joueur humain" << endl;
        else if (choixJoueur == 2)
            cout << "vous avez choisi le joueur robot" << endl;
        else
            cout << "Choix incorrect" << endl;
    } while (choixJoueur != 1 && choixJoueur != 2);
    
    return choixJoueur;
    }

void succes(const char* pathname, string n, int s, int taille) {
    ofstream fd(pathname, ios::out | ios::app); //déclaration du flux et ouverture du fichier
    if (fd) {
        time_t temps;
        struct tm datetime;
        char format[32];
        time(&temps);
        datetime = *localtime(&temps);
        strftime(format, 32, "%Y-%m-%d %H-%M", &datetime);
        fd << n << " ; " <<taille <<" ; "<< s << " ; " << format << endl;
        fd.close();
    } else // sinon
        cerr << "Erreur à l'ouverture !" << endl;
}


Grille_2048* choix_Var_2048(int nGrille, Joueur *J) {
    int var;
    cout << "choisir une variante de 2048 " << endl
            << "Normale --> 1" << endl
            << "Variante Negative --> 2" << endl
            << "Variante Puissance 2, 3,4,5 --> 3" << endl;
    cin >>var;
    while (var != 1 && var != 2 && var != 3) {
        cout << "Choix incorrect" << endl;
        cin >>var;
    }
    if (var==1){
        Grille_2048* Gt=new Grille_2048(nGrille,*J);
        return Gt;
    }
    else if(var==2){
        Grille_2048_VarN* Gt=new Grille_2048_VarN(nGrille,*J);
        return Gt;
    }
    
    return new Grille_2048_VarT(nGrille,*J);;
    
}



void play(Joueur& J, Grille *Gt, int type) {
    J.Jouer(Gt);
    Gt->affiche();
    if (type==1)        
        succes("Score/Score_Taquin", J.getNom(), J.getScore(), Gt->getN());
    else
        succes("Score/Score_2048", J.getNom(), J.getScore(), Gt->getN());
}


int main(int argc, char**argv) {
    srand(time(NULL));
    int nGrille = 3;
    int c = ChoixJeux();
    int cjoueur = ChoixJoueur();
    cout << "Entrez la taille de la grille ? ";
    cin >> nGrille;
    while (nGrille < 2) {
        cout << "Taille trop petite min=2, Veuillez reesayer ?";
        cin >> nGrille;
    }

    if (cjoueur == 1) {
        JoueurHumain J = JoueurHumain();
        if (c == 1) {
            Grille_Taquin Gt = Grille_Taquin(nGrille, J);
            play(J, &Gt,1);
            cout << "\t\tFelicitation !!! " << J.getNom() <<
              "\n\tvous avez reussi a faire le jeu en " << J.getScore() << " coups\n";
        } else {
            Grille_2048 *Gt = choix_Var_2048(nGrille,&J);
            play(J, Gt,0);
            if (Gt->getVal()>objectif){
                    cout << "\t\tFelicitation !!! " << J.getNom() <<
                 "\n\tVoici votre score : " << J.getScore() << "\n";
            }
            else {
                  cout << "Game Over : score " << J.getScore() << "\n";
            }
            
        }
    }
    else {
        JoueurRobot J=JoueurRobot();
        if (c == 1) {
           Grille_Taquin Gt = Grille_Taquin(nGrille, J);
           play(J, &Gt,1);
           cout << "\t\tFelicitation !!! " << J.getNom() <<
              "\n\tvous avez reussi a faire le jeu en " << J.getScore() << " coups\n";
        } else {
            Grille_2048 *Gt = choix_Var_2048(nGrille,&J);
            play(J, Gt,0);
            if (Gt->getVal()>objectif){
                    cout << "\t\tFelicitation !!! " << J.getNom() <<
                 "\n\tVoici votre score : " << J.getScore() << "\n";
            }
            else {
                  cout << "Game Over : score " << J.getScore() << "\n";
            }
        }
    }
    
    return 0;
}
    //Joueur J;
    //Grille Gt(J);



    /*if (c == 1) {
        if (cjoueur == 1) {
            JoueurHumain J = JoueurHumain();
            Grille_Taquin Gt = Grille_Taquin(nGrille, J);
            J.Jouer(&Gt);
            Gt.affiche();
            cout << "\t\tFelicitation !!! " << J.getNom() <<
                    "\n\tvous avez reussi a faire le jeu en " << J.getScore() << " coups\n";
            succes("Score/Score_Taquin", J.getNom(), J.getScore());
        } else {
            JoueurRobot J = JoueurRobot();
            Grille_Taquin Gt = Grille_Taquin(nGrille, J);
            J.Jouer(&Gt);
            Gt.affiche();
            cout << "\t\tFelicitation !!! " << J.getNom() <<
                    "\n\tvous avez reussi a faire le jeu en " << J.getScore() << " coups\n";
            succes("Score/Score_Taquin", J.getNom(), J.getScore());
        }
    } else if (c == 2) {
        if (cjoueur == 1) {
            JoueurHumain J = JoueurHumain();
            int var;
            cout << "choisir une variante de 2048 " << endl
                    << "Normale --> 1" << endl
                    << "Variante Negative --> 2" << endl
                    << "Variante Puissance 3 --> 3" << endl;
            do {
                cin >>var;
                cout << "Choix incorrect" << endl;
            } while (var != 1 && var != 2 && var != 3);
            if (var == 1) {
                Grille_2048 Gt = Grille_2048(nGrille, J);
                J.Jouer(&Gt);
                Gt.affiche();
                if (Gt.getVal() >= 2048) {
                    cout << "\t\tFelicitation !!! " << J.getNom() <<
                            "\n\tVoici votre score : " << J.getScore() << "\n";
                    succes("Score/Score_2048", J.getNom(), J.getScore());
                } else {
                    cout << "Game Over : score " << J.getScore() << "\n";
                    succes("Score/Score_2048", J.getNom(), J.getScore());
                }
            } else if (var == 2) {
                Grille_2048_VarN Gt = Grille_2048_VarN(nGrille, J);
                J.Jouer(&Gt);
                Gt.affiche();
                if (Gt.getVal() >= 2048) {
                    cout << "\t\tFelicitation !!! " << J.getNom() <<
                            "\n\tVoici votre score : " << J.getScore() << "\n";
                    succes("Score/Score_2048", J.getNom(), J.getScore());
                } else {
                    cout << "Game Over : score " << J.getScore() << "\n";
                    succes("Score/Score_2048", J.getNom(), J.getScore());
                }
            } else if (var == 3) {
                Grille_2048_VarT Gt = Grille_2048_VarT(nGrille, J);
                J.Jouer(&Gt);
                Gt.affiche();
                if (Gt.getVal() >= 2048) {
                    cout << "\t\tFelicitation !!! " << J.getNom() <<
                            "\n\tVoici votre score : " << J.getScore() << "\n";
                    succes("Score/Score_2048", J.getNom(), J.getScore());
                } else {
                    cout << "Game Over : score " << J.getScore() << "\n";
                    succes("Score/Score_2048", J.getNom(), J.getScore());
                }
            }
        }
        else {

            JoueurRobot J = JoueurRobot();
            /*J.Jouer(&Gt);
            Gt.affiche();
           if (Gt.getVal()>=2048)
           {    cout << "\t\tFelicitation !!! "<<J.getNom() <<
                        "\n\tVoici votre score : "<<J.getScore()<<"\n";
                succes("Score/Score_2048",J.getNom(), J.getScore());
           }
           else 
           {     cout << "Game Over : score "<<J.getScore()<<"\n";
                succes("Score/Score_2048",J.getNom(), J.getScore());
           }    
     */

    /*
            int var;
            cout << "choisir une variante de 2048 " << endl
                    << "Normale --> 1" << endl
                    << "Variante Negative --> 2" << endl
                    << "Variante Tuile --> 3" << endl;
            do {
                cin >>var;
            } while (var != 1 && var != 2 && var != 3);
            if (var == 1) {
                Grille_2048 Gt = Grille_2048(nGrille, J);
                J.Jouer(&Gt);
                Gt.affiche();
                if (Gt.getVal() >= 2048) {
                    cout << "\t\tFelicitation !!! " << J.getNom() <<
                            "\n\tVoici votre score : " << J.getScore() << "\n";
                    succes("Score/Score_2048", J.getNom(), J.getScore());
                } else {
                    cout << "Game Over : score " << J.getScore() << "\n";
                    succes("Score/Score_2048", J.getNom(), J.getScore());
                }
            } else if (var == 2) {
                Grille_2048_VarN Gt = Grille_2048_VarN(nGrille, J);
                J.Jouer(&Gt);
                Gt.affiche();
                if (Gt.getVal() >= 2048) {
                    cout << "\t\tFelicitation !!! " << J.getNom() <<
                            "\n\tVoici votre score : " << J.getScore() << "\n";
                    succes("Score/Score_2048", J.getNom(), J.getScore());
                } else {
                    cout << "Game Over : score " << J.getScore() << "\n";
                    succes("Score/Score_2048", J.getNom(), J.getScore());
                }
            } else if (var == 3) {
                Grille_2048 Gt = Grille_2048(nGrille, J);
                J.Jouer(&Gt);
                Gt.affiche();
                if (Gt.getVal() >= 2048) {
                    cout << "\t\tFelicitation !!! " << J.getNom() <<
                            "\n\tVoici votre score : " << J.getScore() << "\n";
                    succes("Score/Score_2048", J.getNom(), J.getScore());
                } else {
                    cout << "Game Over : score " << J.getScore() << "\n";
                    succes("Score/Score_2048", J.getNom(), J.getScore());
                }
            }
        }

    }
    return 0;

}*/
