/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grille_Taquin.h
 * Author: netbook
 *
 * Created on 22 novembre 2016, 17:47
 */

#ifndef GRILLE_TAQUIN_H
#define GRILLE_TAQUIN_H


#include "Grille.h"

class Grille_Taquin:public Grille {
/*_______________          
 |  1   4    2   |       ___________________    
 |  6   3    7   | ====> |1|4|2|6|3|7|8|5| |
 |  8   5        |       
 |_______________|

 */

private:
    int pos; //Position de la case Vide |1|4|2|6|3|7|8|5|(pos) |
    void Init();
    int interpreteDir(int dir);
    int getPos();
    void setPos(int i);

 public:
    Grille_Taquin(Joueur &j1);
    Grille_Taquin(int n, Joueur &j1);
    bool deplacer(int dir);
    void update();
    bool isOver();
    virtual ~Grille_Taquin();

};

#endif /* GRILLE_TAQUIN_H */

