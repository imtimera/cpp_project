/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Joueur.h
 * Author: netbook
 *
 * Created on 19 novembre 2016, 13:59
 */
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

#ifndef JOUEUR_H
#define JOUEUR_H

#include "../Case.h"

class Grille;
class Joueur {
private:
    string nom;
    int score;
    void setNom(string n);
    
public:
    Joueur();
    Joueur(string n);
    Joueur(const Joueur& orig);
    string getNom();
    int getScore();
    virtual int generePos();
    virtual ~Joueur();
    void setScore(int v);
    virtual void Jouer(Grille *g);
    
protected:
};

#endif /* JOUEUR_H */

