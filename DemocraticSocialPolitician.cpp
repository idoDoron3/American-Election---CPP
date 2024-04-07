//
// Created by ido on 1/11/23.
//
#include "DemocraticSocialPolitician.h"

bool DemocraticSocialPolitician::isTheSamePoliticBloc(RepublicParty *republicParty) {
    return false;
}

bool DemocraticSocialPolitician::isTheSamePoliticBloc(DemocraticParty *democraticParty) {
    return true;
}

void DemocraticSocialPolitician::PrintPolitician() {
    if(this->chairman== nullptr){
        cout << "Democratic Person:" << this->first_name << " " << this->last_name << ", Id:" << this->id << ", Power:"<< this->power << ", Type:S, Chairman: None"<< endl;
    }
    else {
        cout << "Democratic Person:" << this->first_name << " " << this->last_name << ", Id:" << this->id << ", Power:"
             << this->power << ", Type:S, Chairman: " << this->chairman->getName() << endl;
    }
}
