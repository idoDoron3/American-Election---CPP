//
// Created by ido on 1/11/23.
//
#include "DemocraticLeaderPolitician.h"

bool DemocraticLeaderPolitician::isTheSamePoliticBloc(RepublicParty *republicParty) {
    return false;
}

bool DemocraticLeaderPolitician::isTheSamePoliticBloc(DemocraticParty *democraticParty) {
    return true;
}

void DemocraticLeaderPolitician::PrintPolitician() {
    if(this->chairman== nullptr){
        cout << "Democratic Person:" << this->first_name << " " << this->last_name << ", Id:" << this->id << ", Power:"<< this->power << ", Type:L, Chairman: None"<< endl;
    }
    else {
        cout << "Democratic Person:" << this->first_name << " " << this->last_name << ", Id:" << this->id << ", Power:"<< this->power << ", Type:L, Chairman: " << this->chairman->getName() << endl;
    }
}
