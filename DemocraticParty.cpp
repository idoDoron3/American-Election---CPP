//
// Created by ido on 1/11/23.
//
#include "DemocraticParty.h"

void DemocraticParty::printParty() {
    if(this->chairman== nullptr){
        cout<<"Democrat Party: "<<this->party_name<<", chairman:None, Size:"<<this->getPartySize()<<endl;
    }
    else{
        cout<<"Democrat Party: "<<this->party_name<<", chairman:"<<this->chairman->getName()<<", Size:"<<this->getPartySize()<<endl;
    }
    vector<Politician*>::iterator it;
    for(it = this->party_members.begin(); it!= this->party_members.end(); it++){
        cout<<'\t';
        (*it)->PrintPolitician();
    }
}

bool DemocraticParty::isthesameBloc(Politician *politic) {
    return politic->isTheSamePoliticBloc(this);
}