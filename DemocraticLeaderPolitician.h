//
// Created by ido on 1/11/23.
//

#ifndef AMERICANELECTIONS_DEMOCRATICLEADERPOLITICIAN_H
#define AMERICANELECTIONS_DEMOCRATICLEADERPOLITICIAN_H
#include "Politician.h"
class DemocraticLeaderPolitician: public Politician{
public:
    /* Constructor
    * inputs: name, last name, id, and power
    * the function creates new democratic leader Politician base on politician constructor
    * return: no return value*/
    DemocraticLeaderPolitician(string first_n, string last_n, int id, int power): Politician(first_n, last_n, id, power){};
    /* Destructor
     * inputs:
     * the function destroy Politician object
     * return: no return value*/
    virtual ~DemocraticLeaderPolitician(){};
    /* inputs:
    * the function return the politician power in case of elections.
    * return: int represent the politician power*/
    virtual int getElectionPower(){return this->power;};
    /* inputs:
    * the function return the politician power in case of primaries.
    * return: int represent the politician power*/
    virtual int getPrimariesPower(){return this->power;};
    /* inputs:
    * the function prints the politician.
    * return: no return value*/
    virtual void PrintPolitician();
    /* inputs: democratic party pointer
    * the function return bool value this politician and the input are both democratic.
    * return: */
    virtual bool isTheSamePoliticBloc(DemocraticParty* democraticParty);
    /* inputs: republican party pointer
    * the function return bool value this politician and the input are both republican.
    * return: */
    virtual bool isTheSamePoliticBloc(RepublicParty* republicParty);
};
#endif //AMERICANELECTIONS_DEMOCRATICLEADERPOLITICIAN_H
