//
// Created by ido on 1/11/23.
//

#ifndef AMERICANELECTIONS_POLITICALSYS_H
#define AMERICANELECTIONS_POLITICALSYS_H

#include "Defs.h"
#include "RepublicParty.h"
#include "DemocraticParty.h"
#include "RepublicLeaderPolitician.h"
#include "RepublicSocialPolitician.h"
#include "DemocraticLeaderPolitician.h"
#include "DemocraticSocialPolitician.h"
#include "Exception.h"
#include <sstream>
#include <iostream>
#include <fstream>


class PoliticalSys{
private:
    vector<Politician*> politicians_list;
    vector<Party*> party_list;
    Party* biggest;

public:
    /* Constructor
    * inputs: string
    * the function creates new political system based on the string it reads from
    * return: no return value*/
    PoliticalSys(string);
    /* Destructor
     * inputs:
     * the function destroy the political system object
     * return: no return value*/
    ~PoliticalSys();
    /* inputs:all the fields to create new politician
    * the function checks of all the fields are valid
    * return: bool value of all the fields are legal*/
    bool isValidpoliticiandetails(string id, string power, string bloc, string role);
    /* inputs: string
    * the function checks if this uniq id already exist in the political system
    * return: bool value if exist*/
    bool searchByID(string id);
    /* inputs:2 strings
    * the function checks of all the fields are valid
    * return: bool value of all the fields are legal*/
    bool isValidPartydetails(string name, string bloc);
    /* inputs: string
    * the function checks if this party already exist in the system
    * return: bool if it exist*/
    bool searchPartyByName(string party_name);
    /* inputs: string
    * the function checks if this party already exist in the system
    * return: party pointer if it exist*/
    Party* searchPartyByNameToRemove(string party_name);
    /* inputs:
    * the function get arguments from user and create new politician in the system
    * return: bool value if the add succeed*/
    bool addPolitician();
    /* inputs:all the fields to create new politician
    * the function add new politician to the system
    * return: politician pointer to the new one we create*/
    Politician* addpolitician(string first_name, string last_name, int id, int power, string role, string politicBloc);
    /* inputs:all the fields to create new party
    * the function create new party and add it to the politician system
    * return: party pointer to the new one we create*/
    Party* addParty(string name, string bloc);
    /* inputs: politician pointer
    * the function add the politician to one of the parties if it is possible
    * return: no return value*/
    void addNewPoliticianToParty(Politician* poli);
    /* inputs:
    * the function get arguments from user and create new party in the system
    * return: bool value if the add succeed*/
    bool addParty();
    /* inputs:
    * the function get arguments from user and remove politician from the system
    * return: bool value if the add succeed*/
    bool removePolitician();
    /* inputs:
    * the function get arguments from user and remove party from the system
    * return: bool value if the add succeed*/
    bool removeParty();
    /* inputs: string
    * the function checks if this uniq id already exist in the political system
    * return: politician value if exist*/
    Politician* searchByIDtoRemove(string ids);
    /* inputs: party pointer
    * the function remove the party from the political system
    * return: no value return */
    void removeParty(Party* party);
    /* inputs:
    * the function create elctions result, first primaries and then elections
    * return: no return value*/      void elections();
    Party* elctionsWinner();
    /* inputs:
    * the function print all the politician from the oldest to youngest in the system
    * return: no return value*/
    bool printPoliticians();
    /* inputs:
    * the function print all the parties from the oldest to youngest in the system
    * return: no return value*/
    bool printParties();
    /* inputs:
    * the function print the biggest party by number of members in O(1) time
    * return: no return value*/
    void BiggestParty();
    /* inputs:
    * the function update the pointer to the biggest party
    * return: no return value*/
    void update_biggest_Party();
};

#endif //AMERICANELECTIONS_POLITICALSYS_H