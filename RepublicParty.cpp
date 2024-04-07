//
// Created by ido on 1/11/23.
//
#include "RepublicParty.h"

void RepublicParty::printParty() {
    if(this->chairman== nullptr){
        cout<<"Republican Party: "<<this->party_name<<", chairman:None, Size:"<<this->getPartySize()<<endl;
    }
    else{
        cout<<"Republican Party: "<<this->party_name<<", chairman:"<<this->chairman->getName()<<", Size:"<<this->getPartySize()<<endl;
    }
    vector<Politician*>::iterator it;
    for(it = this->party_members.begin(); it!= this->party_members.end(); it++){
        cout<<'\t';
        (*it)->PrintPolitician();
    }
}

bool RepublicParty::isthesameBloc(Politician *politic) {
    return politic->isTheSamePoliticBloc(this);
}