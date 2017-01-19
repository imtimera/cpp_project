/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Case.h
 * Author: netbook
 *
 * Created on 19 novembre 2016, 15:20
 */

#ifndef CASE_H
#define CASE_H
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <stdlib.h> 

using namespace std;

class Case {
    friend ostream& operator <<(ostream& out,Case& c);
    virtual void put(ostream& out);

public:
    Case();
    virtual int getElement();
    virtual ~Case();

protected:
    virtual void setElement(int a);

};


/*class Case_Occupe:public Case{
public:
    //virtual ostream& operator<<(ostream& out);
    virtual ~Case_Occupe();
};



class Autre_Case: public Case{
private:
    string Contenu;
public :
    void setContenu(string s);
};

/*
class casesokoban:Case_Soke{
    ostream& operator<<(ostream& out, const Case& c);
};*/
#endif /* CASE_H */

