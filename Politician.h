//
// Created by ido on 1/11/23.
//

#ifndef AMERICANELECTIONS_POLITICIAN_H
#define AMERICANELECTIONS_POLITICIAN_H
#include "Defs.h"
#include <iostream>
#include <string>
#include "Party.h"

using namespace std;
class Party;
class DemocraticParty;
class RepublicParty;

class Politician{
protected:
    string first_name;
    string last_name;
    int id;
    Party* _party;
    Politician* chairman;
    int power;

public:
    /* Constructor
    * inputs: name, last name, id, and power
    * the function creates new Politician
    * return: no return value*/
    Politician(string first_n, string last_n, int id, int power);
    /* inputs: Party pointer
    * the function set the politician new party to belongs
    * return: no return value*/
    void setPartyToMember(Party* party);
    /* Destructor
     * inputs:
     * the function destroy Politician object
     * return: no return value*/
    virtual ~Politician(){};
    /* inputs:
    * the function prints the politician, in this case its pure virtual
    * return: no return value*/
    virtual void PrintPolitician()=0;
    /* inputs:
    * the function return the politician power in case of elections, in this case its pure virtual
    * return: int represent the politician power*/
    virtual int getElectionPower()=0;
    /* inputs:
    * the function return the politician power in case of primaries, in this case its pure virtual
    * return: int represent the politician power*/
    virtual int getPrimariesPower()=0;
    /* inputs:
    * the function return the politician name
    * return: string represent the politician name*/
    string getName();
    /* inputs:
    * the function return the politician id
    * return: int represent the politician id*/
    int getId();
    /* inputs: democratic party pointer
    * the function return bool value this politician and the input are both democratic,here it is pure virtual
    * return: */
    virtual bool isTheSamePoliticBloc(DemocraticParty* democraticParty)=0;
    /* inputs: republican party pointer
    * the function return bool value this politician and the input are both republican,here it is pure virtual
    * return: */
    virtual bool isTheSamePoliticBloc(RepublicParty* republicParty)=0;
    /* inputs:
    * get this politician party
    * return:  party pointer */
    Party* getParty();
    /* inputs: string
    * the function update this politician chairman
    * return: no return value*/
    void updateChairman(Politician* chair_name);

};
#endif //AMERICANELECTIONS_POLITICIAN_H
