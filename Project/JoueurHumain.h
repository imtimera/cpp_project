/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JoueurHumain.h
 * Author: netbook
 *
 * Created on 22 novembre 2016, 18:37
 */

#ifndef JOUEURHUMAIN_H
#define JOUEURHUMAIN_H

#include "Joueur/Joueur.h"
class JoueurHumain:public Joueur {

public:
    JoueurHumain();
    JoueurHumain(string nom);
    JoueurHumain(const JoueurHumain& orig);
    void Jouer(Grille *g) override;
    int generePos() override;
    virtual ~JoueurHumain();


};

#endif /* JOUEURHUMAIN_H */

