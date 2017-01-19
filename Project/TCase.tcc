/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCase.tcc
 * Author: netbook
 *
 * Created on 28 décembre 2016, 17:47
 */

#ifndef TCASE_TCC
#define TCASE_TCC
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <stdlib.h> 

using namespace std;

template <class T>
class TCase{
protected :
    T contenu;

public:
    friend ostream& operator <<(ostream& out,TCase& c){
        c.put(out);
        return out;
    }
    virtual void put(ostream& out){
        out <<contenu;
    }
    TCase(T el):contenu(el){
        
    }
    TCase(const TCase& orig):contenu(orig.contenu){
        
    }
    T getContenu(){
        return contenu;
    }
    void setContenu(T e){
        contenu=e;
    }
    virtual ~TCase(){
        delete &contenu;
    }

private:

};

#endif /* TCASE_TCC */

