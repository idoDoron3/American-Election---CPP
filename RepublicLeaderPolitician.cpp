//
// Created by ido on 1/11/23.
//
#include "RepublicLeaderPolitician.h"

bool RepublicLeaderPolitician::isTheSamePoliticBloc(RepublicParty *republicParty) {
    return true;
}

bool RepublicLeaderPolitician::isTheSamePoliticBloc(DemocraticParty *democraticParty) {
    return false;
}

void RepublicLeaderPolitician::PrintPolitician() {
    if(this->chairman== nullptr){
        cout << "Republican Person:" << this->first_name << " " << this->last_name << ", Id:" << this->id << ", Power:"<< this->power << ", Type:L, Chairman: None"<< endl;
    }
    else {
        cout << "Republican Person:" << this->first_name << " " << this->last_name << ", Id:" << this->id << ", Power:"
             << this->power << ", Type:L, Chairman: " << this->chairman->getName() << endl;
    }
}
