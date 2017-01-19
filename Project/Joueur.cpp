/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Joueur.cpp
 * Author: netbook
 * 
 * Created on 19 novembre 2016, 13:59
 */

#include "Joueur/Joueur.h"

/**
 * Constructeur par defaut
 */
Joueur::Joueur(): nom("anonymous"), score(0) {
}

/**
 * Constructeur avec un nom
 * @param nom
 */
Joueur::Joueur(string n): nom(n), score(0) {
}

/**
 * constructeur de copie
 * @param orig
 */
Joueur::Joueur(const Joueur& orig):nom(orig.nom),score(orig.score) {
}


/**
 * retourne le nom du joueur
 * @return string 
 */
string Joueur::getNom(){
    return nom;
}


/**
 * Mis à jour du score
 * @param v
 */
void Joueur::setScore(int v){
    score=v;
}

/**
 * obtention du score
 * @return 
 */
int Joueur::getScore(){
    return score;
}

/**
 * Le joueur donnant un position valide
 * @return int
 */
int Joueur::generePos(){
    srand(time(NULL)); 
    return rand()%4;
}

/**
 * mis a jour du nom du joueur
 * @param n
 */
void Joueur::setNom(string n){
    nom=n;
}

void Joueur::Jouer(Grille *g){
       
}
/*void Joueur::Jouer(Grille* g){
    
}*/

Joueur::~Joueur() {
   
}

