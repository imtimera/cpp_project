/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grille.cpp
 * Author: netbook
 * 
 * Created on 19 novembre 2016, 18:29
 */

#include <string.h>
#include <cstddef>
#include <complex>
#include "Grille.h"

/**
 * Constructeur d'une grille 3X3 avec avec un joueur j1
 * @param j1 Joueur de la partie
 */
Grille::Grille(Joueur &j1): ncase(9), j(j1){
     board=new Case*[ncase];
    for(int i=0;i<ncase;i++){
        board[i]=new Case;
    }
}

/**
 * Constructeur d'une grille nXn avec avec un joueur j1
 * @param n Taille de la ligne de la grille
 * @param j1 Joueur de la partie
 */

Grille::Grille(int n,Joueur &j): ncase(n*n),j(j) {
    board=new Case*[ncase];
    for(int i=0;i<ncase;i++){
        board[i]=new Case;
    }
}


/**
 * Interpretation d'une direction donnée par l'utilisateur
 * diffence entre les deux Jeux implementés
 * @param dir
 * @return 
 */
int Grille::interpreteDir(int dir){
    return 0;
}
Grille::Grille(const Grille& orig): ncase(orig.getN()), j(orig.getJoueur()) {
    board=new Case*[ncase];
    for(int i=0;i<ncase;i++){
       board[i]=orig.getContenu(i);
       
    }
}

/**
 * Initiialisation d'une ceci depend du jeux choisi
 */
void Grille::Init(){
    
     
}

/**
 * retourne la taille n*n du tableau
 * @return int 
 */
int Grille::getN() const{
    return ncase;
}

/**
 * retourne la taille d'une ligne
 * @return int 
 */
int Grille::getTailleLigne(){
    return sqrt(ncase);
}


/**
 * changer le contenu de board[i] par c
 * @param i
 * @param c
 */
void Grille::setBoard(int i, Case* c){
    board[i]=c;
}



/**
 * ?Un coup est-il encore autorisé?
 * @return bool
 */
bool Grille::isOver(){
    return false;
}


void Grille::setN(int n){
    ncase=n;
}


void Grille::setJoueur(Joueur& joueur){
    j=joueur;
}


Joueur& Grille::getJoueur() const{
   return  j;
}

/**
 * Retourne le contenu de board[i]
 * @param i position dans le board
 * @return 
 */
Case* Grille::getContenu(int i) const{
    return board[i];
}

/**
 * Deplacer vers une direction dir est il possible?
 * Si oui alors deplacer
 * @param dir
 * @return bool 
 */
bool Grille::deplacer(int dir){
    return false;
       
}


/**
 * Echanger deux cases de la grille util en tout jeu de ce stlye
 * @param i
 * @param j
 */
void Grille::Echange(int i, int j){
    Case *tmp=new Case();
    tmp=board[i];
    board[i]=board[j];
    board[j]=tmp;
}


/**
 * Changer le Score du joueur actuel
 * @param v
 */
void Grille::setScore(int v){
    j.setScore(v);

}


/**
 * retourne le Score du joueur actuel
 * @return 
 */
int Grille::getScore(){
    j.getScore();
}


/**
 * Fonction d'affichage d'une grille
 */
void Grille::affiche(){
    int i;
    int k=getTailleLigne();
    cout<<endl<<" ";
    for (int i=0; i<k; i++)
        cout <<"___________";
    cout<<endl;
    for(i=0;i<k;i++){
        cout <<"|___";
        for(int j=0;j<k-1;j++){ 
            cout << *board[i*k+j]<<"___|___";
        }
        cout << *board[i*k+(k-1)]<< "___|\n";
    }
}

Grille::~Grille() {
    delete [] board;
}
