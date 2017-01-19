/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JoueurRobot.cpp
 * Author: netbook
 * 
 * Created on 22 novembre 2016, 18:47
 */

#include "JoueurRobot.h"
#include "Grille.h"

JoueurRobot::JoueurRobot():Joueur("Robot") {
    
}
JoueurRobot::JoueurRobot(string n):Joueur(n) {
    
}

JoueurRobot::JoueurRobot(const JoueurRobot& orig):Joueur(orig) {
}
/**
 * generation d'une position aleatoire avec l'utilisation 
 * d'un tableau pour des raisons de performances on evite 
 * une boucle while()
 * @return 
 */
int JoueurRobot::generePos(){
    int tab[]={1,2,3,5};
    int i=abs(rand()%4);
                            
    /* tab ={1;2;3;5}
     * 1 --> Gauche ~~ 2 --> Bas    ^
     * 3 --> Droite ~~ 5 --> Haut <   >
     *                              v
     */
    return  tab[i];
    
}

void JoueurRobot::Jouer(Grille *Gt){
        while (!Gt->isOver()){
        int dir;
        for (int i=0; i<Gt->getTailleLigne(); i++)
            cout <<"*-*-*-*-*-*";
        Gt->affiche();
        cout<<endl;
        dir=generePos();        
        while (Gt->deplacer(dir)==false){
            //cout << dir<<" : Direction ivalide? \n";
            dir=generePos();        
        }           
    }
}

JoueurRobot::~JoueurRobot() {
}

