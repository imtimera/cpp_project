/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grille_2048.cpp
 * Author: netbook
 * 
 * Created on 22 novembre 2016, 17:38
 */

#include <cmath>
#include <complex>
#include "Grille_2048.h"

#define objectif 2048
/*
------------------------------        ^  
|         |         |         |       5
|         |         |    4    |   <-1    3->
|    2    |         |         |       2 
------------------------------        v 

 */

Grille_2048::Grille_2048(Joueur & j):  valMax(0),Grille(j) {
    Init();
    
}

Grille_2048::Grille_2048(int n, Joueur & j): valMax(0) , Grille(n,j){
     Init();
}


Grille_2048::Grille_2048(const Grille_2048& orig):valMax(orig.valMax), Grille(orig){
    
}
/**
 * 
 * Fonction d'initialisation de la grille 2048
 * avec deux case occupés 2 et 4 dans des pos aleatoires
 */
void Grille_2048::Init(){
    Cdeplacable=new bool[getN()];
    for (int i=0; i<getN(); i++){
        Cdeplacable[i]=true;
    }
    for (int i=0; i<getN(); i++){
        setBoard(i, new Case_Vide());
        
    }
    //srand(time(NULL));
    int alea1=abs(rand()%getN());
    int alea2=abs(rand()%getN());
    while(alea1==alea2){
        alea2=abs(rand()%getN());
    }
    
    setBoard(alea1,new Case_Entier(2));
    setBoard(alea2,new Case_Entier(4));
    
}


/**
 * Cette fonction effectue i rotations horaire de 90°
 * @param i nombre de rotations horaire
 * 
 */
void Grille_2048::Rotation(int i){
    for (int k=0; k<i; k++)
        RotationHoraire();
}


/**
 * Cette fonction permet de faire une rotation de 90°
 * de la grille, elle nous evitera de faire 
 * deplacement Gauche Bas Haut   
 */
void Grille_2048::RotationHoraire(){
    int n=getN();
    int t=sqrt(n);
    Case** tmp=new Case*[n];
    for(int i=0;i<n;i++){
        tmp[i]=new Case;
    }
    
    for(int i=0;i<n;i++){
        tmp[i]=getContenu(i);
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            int a=i*t+j;
            int b=(t-1-i)*t+j;
            //cout << "a :"<<a <<" --> b  " <<b<<endl;
            setBoard(i*t+j,tmp[(t-1-j)*t+i]);
        }
    }
    delete [] tmp;
}


/**
 * renvoie la premiere case disponible a partir 
 * de la position i,j en partant de la gauche
 * @param i la ligne dans la grille 
 * @param j la colonne dans la grille
 * @return Case* 
 */
Case* Grille_2048::PremierCaseDispo(int i, int j){
    int t=sqrt(getN());
    int k=(DernierK(i,j));
    //cout <<"case Dispo "<<(i*t)+k<<endl;
    return getContenu((i*t)+k);
    
}


/**
 * Teste s'il n ya pas de cases occupé entre i,j et i,k pour pouvoir faire la fusion i,j i,k
 * @param i la ligne dans la grille
 * @param j la colone dans la grille
 * @param k une autre colone dans la grille
 * @return bool
 */
bool Grille_2048::noElement(int i,int j, int k){
    int t=sqrt(getN());
    for (int ii=j+1; ii<k; ii++){
        if (getContenu(i*t+ii)->getElement()!=0)
            return false;
    }
    return true;
}


/**
 * La derniere position k a la ligne i dont le contenu est vide 
 * ou de valeur egal au contenu de i,j
 * @param i
 * @param j
 * @return int
 */
int Grille_2048::DernierK(int i,int j){
    int t=sqrt(getN());
    for(int k=t-1; k>j; k--){
        if(getContenu(i*t+k)->getElement()==0 
                    || abs(getContenu(i*t+k)->getElement())==abs(getContenu(i*t+j)->getElement()) 
                    && noElement(i,j,k)){
            //cout <<"ligne "<<i<<"k"<<k<<endl;
            return k;
        }
    }
        return j;
}


/**
 * Deplace tous les elements vers la droite si,biensur, 
 * le deplacement reste possible. Notez que c'est la seule 
 * fonction de deplacement pour tout autre direction on effectue 
 * une voir plusieurs rotations puis on retablit le tableau
 * avec un nombre total de rotation egal a 0[4]
 * @return bool 
 */
bool Grille_2048::deplacerDroite() {
    int n=getN();
    int t=sqrt(getN());
    int nbDeplacement=0;
    for (int i=0; i<getN(); i++){
        Cdeplacable[i]=true;
    }
    
    for (int i=0; i<t; i++){
        for (int j=t-1; j>=0; j-- ){
            if (getContenu((i*t+j))->getElement()!=0){
                //cout <<(i*t+j)<<" ";
                //cout <<"changm "<<i*t+DernierK(i,j)<<" "<<getContenu(i+j*t)->getElement()<<endl;
                int k=DernierK(i,j);
                if(k!=j && abs(getContenu(i*t+k)->getElement())!=abs(getContenu(i*t+j)->getElement()))
                    Echange(i*t+k,(i*t+j));
                else if (k!=j && abs(getContenu(i*t+k)->getElement())==abs(getContenu(i*t+j)->getElement())){
                    if (Cdeplacable[i*t+k])
                        fusion((i*t+j),(i*t+k));
                    else 
                        Echange(i*t+(k-1),(i*t+j));
                }
                k!=j?nbDeplacement++:nbDeplacement;
            }
       }
    }
    return nbDeplacement==0?false:true;
        
    
}


/**
 * Deplace la grille en fonction de la direction donnée par l'utilisateur
 * un deplacement  vers la droite ne necessite pas de rotation 
 * cependant toute autre direction necessite 1 2 voire 3 rotations
 * @param dir direction donnée par l'utilisateur
 * @return bool
 */
bool Grille_2048::deplacer(int dir){
    if (dir ==3){ //Aler a droite
        if (deplacerDroite())
            GenereAlea();
        return true;
    }
    else if (dir==1){//Aller a gauche
        Rotation(2);
        if (deplacerDroite())
            GenereAlea();
        Rotation(2);
        return true;
    }
    
    else if (dir==5){//Aller en haut
        RotationHoraire();
        if (deplacerDroite())
            GenereAlea();
        Rotation(3);
        return true;
    }
    else if (dir==2){//Aller en bas
        Rotation(3);
        if (deplacerDroite())
            GenereAlea();
        RotationHoraire();
        return true;
    }
    
    return false;
}


/**
 * Mise a jour de la valeur maximale
 * @param v
 */
void Grille_2048::setVal(int v){
    valMax=v;
}

/**
 * Cette fonction teste si la grille est toujours deplacable
 * meme si toutes la grille  est occupée, il y a t'il des element
 * de meme valeur voisin?
 * @return true or false
 */
bool Grille_2048::deplacable(){
    int t=sqrt(getN());
    if (t>2){
        /*On traite le millieu d'abord i.e si deux case voisines ont la 
         * meme valeur elles peuvent se combiner donc le n'est pas encore terminé
         * voisine voulant dire voisine sur la mm ligne ou la colonne 
         */
        for (int i=1; i<t-1; i++){
            for(int j=1; j<t-1; j++){
                int e =abs(getContenu(i*t+j)->getElement());
                if (e==abs(getContenu(i*t+j-1)->getElement())   
                    || e==abs(getContenu(i*t+j+1)->getElement())
                    || e==abs(getContenu((i+1)*t+j)->getElement())
                    || e==abs(getContenu((i-1)*t+j)->getElement()))
                  return true;
            }
        }
        /* 
         * Si deux cases voisine de la 1ere ligne ont la mm valeur
         * On arrete pas le jeu , le joueur a donc la possibilité de rejouer
         *  */
        for (int i=0; i<t-1; i++){
            if (abs(getContenu(i)->getElement())==abs(getContenu(i+1)->getElement()))
                return true;
        }
        /*
         *Idem traitement de la 1ere colonne  
         */
        for (int i=0; i<t-1; i++){
            if (abs(getContenu(i*t)->getElement())==abs(getContenu((i+1)*t)->getElement()))
                return true;
        }
        /*
         *Idem traitement de la derniere colonne  
         */
        
        for (int i=1; i<t-1; i++){
           if (abs(getContenu(i*t)->getElement())==abs(getContenu((i+1)*t)->getElement()))
                return true;
        }
        
        /*
         *Idem traitement de la derniere ligne  
         */
        
        for (int i=0; i<t-1; i++){
              if (abs(getContenu((t-1)*t+i)->getElement())==abs(getContenu((t-1)*t+i+1)->getElement()))
                return true;
        
        }
    }
    else if (t==2){
        int e=abs(getContenu(0)->getElement());
        if (e==abs(getContenu(1)->getElement()) 
            || e==abs(getContenu(2)->getElement())
            || abs(getContenu(1)->getElement())==abs(getContenu(3)->getElement())
            || abs(getContenu(2)->getElement())==abs(getContenu(3)->getElement()))
                  return true;
 
    }
    return false;
}


/**
 * Fusionner deux element de meme valeur, en supprimant le premier
 * et en mettant, si necessaire, a jour la valMax
 * @param i position du 1er element
 * @param j position du 2e element
 */
void Grille_2048::fusion(int i, int j){
    Case_Entier* c=new Case_Entier(2*getContenu(j)->getElement());
    //c->setElement(2*getContenu(j)->getElement());
    setBoard(j,c);
    Cdeplacable[j]=false;
    setScore(getScore()+c->getElement());
    if (c->getVal()>valMax)
        valMax=c->getElement();
    setBoard(i,new Case_Vide);
    
}


int Grille_2048::interpreteDir(int dir){
    return 0;
}


int Grille_2048::getVal(){
    return valMax;
}


/**
 * Generer Aleatoirement une case 2 ou une case 4 dans le tableau
 */
void Grille_2048::GenereAlea(){
    int alea1=abs(rand()%getN());
    int alea2=abs(rand()%6);
    while(getContenu(alea1)->getElement()!=0)
        alea1=abs(rand()%getN());
    if (alea2<=3)
        setBoard(alea1,new Case_Entier(2));
    else 
        setBoard(alea1,new Case_Entier(4));
}


/**
 * test si un coup est toujour possible
 * - On s'arrete des que l'on atteint 2048
 * @return bool 
 */
bool Grille_2048::isOver(){
    if (valMax>=objectif){    
        return true;
    }for (int i=0; i<getN(); i++){
        if (getContenu(i)->getElement()==0)
            return false;
    }
    while(deplacable()){
         return false;
    }
    return true;
}


Grille_2048::~Grille_2048(){
    delete []Cdeplacable;
}
