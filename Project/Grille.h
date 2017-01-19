/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grille.h
 * Author: netbook
 *
 * Created on 19 novembre 2016, 18:29
 */

#ifndef GRILLE_H
#define GRILLE_H
#include "Case_Entier.h"
#include "Case_Vide.h"
#include "JoueurHumain.h"
#include "JoueurRobot.h"
#include <math.h> 
#include <algorithm>

class Grille {


    private:
        int ncase;
        Joueur& j;
        Case **board;
        void setN(int n); 
        void setJoueur(Joueur &);
        
public:
        Grille(Joueur &j1);
        Grille(int n,Joueur &j1);
        Grille(const Grille &);
        int getN() const;
        int getTailleLigne();
        virtual int getScore();
        virtual bool deplacer(int dir);
        Joueur& getJoueur() const;
        bool estOccupe(int i, int j);
        //virtual void update();
        virtual bool isOver(); 
        void affiche();
        virtual ~Grille();

protected:
    virtual void Init();
    void setBoard(int i,Case* c);
    void Echange(int i, int j);
    virtual void setScore(int s);
    virtual int interpreteDir(int dir); 
    Case * getContenu(int i) const;
            
                   


};

#endif /* GRILLE_H */

