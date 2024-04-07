//
// Created by ido on 1/11/23.
//

#ifndef AMERICANELECTIONS_REPUBLICPARTY_H
#define AMERICANELECTIONS_REPUBLICPARTY_H
#include "Party.h"
class Politician;

#include "Party.h"



class RepublicParty: public Party {
public:
    /* Constructor
    * inputs: name
    * the function creates new Party base on party class constructor
    * return: no return value*/
    RepublicParty(string name1) : Party(name1) {};
    /* Destructor
    * inputs:
    * the function destroy Party object
    * return: no return value*/
    virtual ~RepublicParty() {};
    /* inputs:
    * the function prints the republican party
    * return: no return value*/
    virtual void printParty();
    /* inputs: politician
    * the function checks if the input politician and this party are from the same politic bloc.
    * return: no return value*/
    virtual bool isthesameBloc(Politician *politician);

};
#endif //AMERICANELECTIONS_REPUBLICPARTY_H
