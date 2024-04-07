//
// Created by ido on 1/11/23.
//
#include "Politician.h"

Politician::Politician(string first_n, string last_n, int id, int power) {
    this->first_name=first_n;
    this->last_name=last_n;
    this->id=id;
    this->power=power;
    this->_party= nullptr;
    this->chairman= nullptr;
}

string Politician::getName() {
    return this->first_name;
}

int Politician::getId() {
    return this->id;
}

Party* Politician::getParty() {
    return this->_party;
}

void Politician::updateChairman(Politician* chair_name) {
    this->chairman=chair_name;
}

void Politician::setPartyToMember(Party *party) {
    this->_party=party;
}