//
// Created by ido on 1/11/23.
//
#include "RepublicSocialPolitician.h"

bool RepublicSocialPolitician::isTheSamePoliticBloc(RepublicParty *republicParty) {
    return true;
}

bool RepublicSocialPolitician::isTheSamePoliticBloc(DemocraticParty *democraticParty) {
    return false;
}

void RepublicSocialPolitician::PrintPolitician() {
    if(this->chairman== nullptr){
        cout << "Republican Person:" << this->first_name << " " << this->last_name << ", Id:" << this->id << ", Power:"<< this->power << ", Type:S, Chairman: None"<< endl;
    }
    else {
        cout << "Republican Person:" << this->first_name << " " << this->last_name << ", Id:" << this->id << ", Power:"
             << this->power << ", Type:S, Chairman: " << this->chairman->getName() << endl;
    }
}
