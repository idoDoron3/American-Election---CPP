//
// Created by ido on 1/11/23.
//

#ifndef AMERICANELECTIONS_PARTY_H
#define AMERICANELECTIONS_PARTY_H
#include "Defs.h"
#include "Politician.h"
using namespace std;
class Politician;


class Party{
protected:
    string party_name;
    Politician* chairman;
    vector <Politician*> party_members;

public:
    /* Constructor
    * inputs: name
    * the function creates new Party
    * return: no return value*/
    Party(string name);
    /* Destructor
    * inputs:
    * the function destroy Party object
    * return: no return value*/
    virtual ~Party(){};
    /* inputs:
    * the function prints the party, in this case its pure virtual
    * return: no return value*/
    virtual void printParty()=0;
    /* inputs: Politician* object
    * the function adds this politician to this party
    * return: bool if the add succeed*/
    bool addPoliticianToParty(Politician* politician);
    /* inputs: Politician* object
    * the function remove this politician to this party
    * return: bool if the remove succeed*/
    bool removePoliticianFromParty(Politician* politician);
    /* inputs:
    * the function chose the most powerful leader politician from this party members
    * return: no return value*/
    void primaries();
    /* inputs:
    * the function calculate this party power when elections
    * return: int represent the party power*/
    int powerCalculate();
    /* inputs:
    * the function find the number of members
    * return: int represent this party number of members*/
    int getPartySize();
    /* inputs:
    *
    * return: this party name as string*/
    string getParty_name();
    /* inputs:
    *
    * return: this party chairman as string*/
    string  getParty_chairman();
    /* inputs:
    *
    * return: pointer to this party members list*/
    vector<Politician*> getPattyMembers();
    /* inputs: politician
    * the function checks if the input politician and this party are from the same politic bloc.
    *in this case the function is pure virtual and does not do anything
    * return: no return value*/
    virtual bool isthesameBloc(Politician* politician)=0;
    /* inputs:
    * the function prints the party, in this case its pure virtual
    * return: no return value*/
    void notifyUpdateChairmen(Politician* chair_name);
};

#endif //AMERICANELECTIONS_PARTY_H
