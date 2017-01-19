/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grille_Taquin.cpp
 * Author: netbook
 * 
 * Created on 22 novembre 2016, 17:47
 */

#include "Grille_Taquin.h"
#include <list>
#include <vector>

/*
 ------------------------------
|    2    |    6    |    7    |   
|    4    |    3    |    8    |   
|    5    |    1    |         |   
------------------------------
 */


/**
 * Constructeur d'une grille taquin de 3x3 Cases
 * Avec joueur courant j1
 * @param j1 Joueur de la partie
 */
Grille_Taquin::Grille_Taquin(Joueur &j1): Grille(j1), pos(8){
   Init();
}

/**
 * Constructeur d'une grille taquin de nxn Cases
 * Avec joueur courant j1
 * @param n taille de la ligne
 * @param j1 Joueur de la partie
 */
Grille_Taquin::Grille_Taquin(int n, Joueur &j1): Grille(n,j1), pos(n-1){
    Init();
}

/**
 * Retourne la position de la case vide dans la grille
 * @return int
 */
int Grille_Taquin::getPos(){
    return pos;
}
    
/**
 * Mise a jour de la position de la case vide
 * @param i
 */
void Grille_Taquin::setPos(int i){
    pos=i;
}

/**
 * Methode d'initialisation de la grille 
 */
void Grille_Taquin::Init(){
    srand(time(NULL));
    setBoard(getN()-1,new Case_Vide());
    setPos(getN()-1);
    /*
     *Pour generer des positions aleatoires on fait appel
     * au vector et a la fonction random_shufflet de 
     * la librairie algorithm puis on ajoute les elements 
     * du vector à la grille et le travail d'init est fait 
     */
    vector<int> v;
    for (int i=0; i<getN()-1; i++){
        v.push_back(i+1);
    }
    random_shuffle(v.begin(), v.end());
    
    for (int i=0; i<getN()-1; i++){
        int a=v.at(i);
        setBoard(i, new Case_Entier(a));    
    }
    /*
     *gain impossible au premier coup 
     */
    while (isOver()){
     random_shuffle(v.begin(), v.end());
       for (int i=0; i<getN()-1; i++){
            int a=v.at(i);
            setBoard(i, new Case_Entier(a));    
        }
    }
    
}

/**
 * Interpretation d'une direction dir
 * en fonction du dir on met a jour la position 
 * de la case vide
 * @param dir
 * @return int
 */
int Grille_Taquin::interpreteDir(int dir){
    int i;
    switch (dir){
            case 1:{
                i=pos+1; // |X|X|X| |3|X|X| --> |X|X|X|3| |X|X|
                break;
            }
            case 2:{ 
                i=pos-getTailleLigne(); // |6|X|X| |X|X| --> | |X|X|6|X|X|
                break;
            }
            case 3:{
                i=pos-1; // |X|X|X|8| |X| --> |X|X|X| |8|X|
                break;
            }  
            case 5:{
                i=pos+getTailleLigne();  //| |X|X|2|X|X|X| --> |2|X|X| |X|X|X|
                break;
            }
        default:
            i=0;
    }
    return i;
}



bool Grille_Taquin::deplacer(int dir){
    /*             |
     *             v5
     dir :    1->      <-3 du clavier
                   ^2
                   |
     */
    int gp=getPos();
    int gtl=getTailleLigne();
    int n=getN();
    if (dir==2 && gp<=(gtl-1) ) //Quand Vide est en haut on ne peut aller plus haut
        return false;
    if(dir==1 && (gp%gtl==gtl-1))//Quand Vide est a droite on ne peut aller plus a droite
        return false;
    //if(dir==5 && (getN()%getPos()>=1 && getN()%getPos()<=getTailleLigne())) //Quand Vide est en bas on ne peut aller plus bas
    if(dir==5 && (gp>=n-gtl)) //Quand Vide est en bas on ne peut aller plus bas
        return false;
    if (dir ==3 && (gp%gtl==0 )) ////Quand Vide est a gauche on ne peut aller plus a gauche
        return false;
    
    int i=interpreteDir(dir);
    Echange(i,pos);
    int s=getScore();
    setScore(s+1);
    setPos(i);
    return true;         
     
}

/**
 * ? un coup est-il toujours possible?
 * Pour une meilleur performance cette fontion 
 * test d'abord si le vide est en derniere position?
 * puis elle teste si les cases sont ordonnées:false
 * @return 
 */
bool Grille_Taquin::isOver(){
    //Il faut que la case vide soit en derniere position
    if (pos!=getN()-1)
        return false;
    for (int i=0; i<getN()-1; i++){
        if (getContenu(i)->getElement()!=i+1)
            return false;
    }
    return true;
 }
/*Grille_Taquin::Grille_Taquin(const Grille_Taquin& orig) {
}*/

Grille_Taquin::~Grille_Taquin() {
}