//
// Created by ido on 1/11/23.
//
#include "Party.h"

Party::Party(string name) {
    this->party_name=name;
    this->chairman= nullptr;
}

bool Party::addPoliticianToParty(Politician* politician) {
    if(politician== nullptr){
        return false;
    }
    if(isthesameBloc(politician)){
        this->party_members.push_back(politician);
        if(politician->getParty()!= nullptr){
            Party* update = politician->getParty();
            update->removePoliticianFromParty(politician);
            politician->setPartyToMember(nullptr);
            politician->updateChairman(nullptr);
        }
        politician->setPartyToMember(this);
        politician->updateChairman(this->chairman);
        return true;
    }
    else{
        return false;
    }

}

bool Party::removePoliticianFromParty(Politician *politician) {
    int numOfPol = this->party_members.size();
    vector<Politician*>::iterator it;
    for( it = this->party_members.begin(); it != this->party_members.end();it++) {
        if ((*it)->getId() == politician->getId()) {
            break;
        }
    }
    this->party_members.erase(it);
    int num2 = this->party_members.size();
    if(numOfPol == num2){
        return false;
    }
    else{
        if(this->chairman == nullptr){
            return true;
        }
        else if(this->chairman->getId() == politician->getId()){
            this->chairman= nullptr;
            this->notifyUpdateChairmen(nullptr);
            return true;
        }
        return false;
    }
}

string Party::getParty_name() {
    return this->party_name;
}

string Party::getParty_chairman() {
    if(this->chairman== nullptr){
        return "None";
    }
    return this->chairman->getName();
}

vector<Politician *> Party::getPattyMembers() {
    return this->party_members;
}

int Party::getPartySize() {
    return this->party_members.size();
}

int Party::powerCalculate() {
    int party_power = 0;
    if(this->party_members.size()==0){
        return 0;
    }
    vector<Politician*>::iterator it;
    for(it = this->party_members.begin(); it!= this->party_members.end(); it++){
        party_power += (*it)->getElectionPower();
    }
    return party_power;
}

void Party::primaries() {
    int max =-1;
    Politician* max_power = nullptr;
    vector<Politician*>::iterator it;
    for(it = this->party_members.begin(); it!= this->party_members.end(); it++){
        if((*it)->getPrimariesPower() > max){
            max = (*it)->getPrimariesPower();
            max_power=(*it);
        }
    }

    if(max==-1){
        this->chairman = nullptr;
        notifyUpdateChairmen(nullptr);
    }
    else{
        this->chairman=max_power;
        notifyUpdateChairmen(max_power);
    }
    if(this->chairman == nullptr){
        cout<<"None is the chairman of "<<this->party_name<<endl;
    }
    else {
        cout << this->chairman->getName() << " is the chairman of " << this->party_name << endl;
    }
}

void Party::notifyUpdateChairmen(Politician* chair_name) {
    vector<Politician*>::iterator it;
    for(it = this->party_members.begin(); it!=this->party_members.end();it++){
        (*it)->updateChairman(chair_name);
    }
}