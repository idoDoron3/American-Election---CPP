//
// Created by ido on 1/11/23.
//

#include "PoliticalSys.h"
#include <string>


PoliticalSys::PoliticalSys(string confi) {
    ifstream sysFile(confi);//open the file
    string curr_line;
    getline(sysFile,curr_line);//reads the firs line - headline
    if (curr_line.back() == '\r') {
        curr_line.erase(curr_line.size() - 1);
    }
    getline(sysFile,curr_line);//the lune we want to work on
    if (curr_line.back() == '\r') {
        curr_line.erase(curr_line.size() - 1);
    }
    while(curr_line.compare("Parties:")!= 0){
        istringstream linetoAdj(curr_line);
        string first_n,last_n, id, power, role, bloc;
        getline(linetoAdj, first_n, ' ');
        getline(linetoAdj, last_n, ' ');
        getline(linetoAdj, id, ' ');
        getline(linetoAdj, power, ' ');
        getline(linetoAdj, bloc, ' ');
        getline(linetoAdj, role, ' ');
        int ID = stoi(id);
        int Power = stoi(power);
        addpolitician(first_n, last_n, ID, Power, role, bloc);
        getline(sysFile,curr_line);
        if (curr_line.back() == '\r') {
            curr_line.erase(curr_line.size() - 1);
        }
    }
    while(getline(sysFile,curr_line)){//we already read the party headline line
        if (curr_line.back() == '\r') {
            curr_line.erase(curr_line.size() - 1);
        }
        istringstream linetoAdj(curr_line);
        string name1,bloc1;
        getline(linetoAdj, name1, ' ');
        getline(linetoAdj, bloc1, ' ');
        addParty(name1, bloc1);
    }
    sysFile.close();
    this->update_biggest_Party();

}

Politician* PoliticalSys::addpolitician(string first_name, string last_name, int id, int power, string role, string politicBloc) {
    Politician* poli;

    if((politicBloc.compare("D")==0)&&(role.compare("L"))==0){
        poli = new DemocraticLeaderPolitician(first_name,last_name, id, power);
        this->politicians_list.push_back(poli);//add poli to the list of politician
        return poli;
    }
    else if((politicBloc.compare("D")==0)&&(role.compare("S"))==0){
        poli = new DemocraticSocialPolitician(first_name,last_name, id, power);
        this->politicians_list.push_back(poli);//add poli to the list of politician
        return poli;
    }
    else if((politicBloc.compare("R")==0)&&(role.compare("L"))==0) {
        poli = new RepublicLeaderPolitician(first_name, last_name, id, power);
        this->politicians_list.push_back(poli);//add poli to the list of politician
        return poli;
    }
    else if((politicBloc.compare("R")==0)&&(role.compare("S"))==0) {
        poli = new RepublicSocialPolitician(first_name, last_name, id, power);
        this->politicians_list.push_back(poli);//add poli to the list of politician
        return poli;
    }
    return poli;
}

void PoliticalSys::addNewPoliticianToParty(Politician *poli) {//find poli match party

    vector<Party*>::iterator it;
    for(it =this->party_list.begin(); it!=this->party_list.end(); it++){
        if(poli->getParty()== nullptr){//poli has no party he belongs to and they in the same bloc
           (*it)->addPoliticianToParty(poli);
        }
        else if((poli->getParty()->getPartySize())>((*it)->getPartySize())){//poli party has more members than the one he checks
           (*it)->addPoliticianToParty(poli);
        }
    }
    return ;
}


bool PoliticalSys::addPolitician() {
    bool add = false;
    string first_name;
    string last_name;
    string id;
    string power;
    string bloc;
    string role;
    cout << "---Create Politician---" << endl;
    while(add== false) {
        cout << "First name:" << endl;
        cin >> first_name;
        cout << "Last name:" << endl;
        cin >> last_name;
        cout << "ID:" << endl;
        cin >> id;
        cout << "Power:" << endl;
        cin >> power;
        cout << "Republican or Democratic person" << endl;
        cin >> bloc;
        cout << "Leader or Social" << endl;
        cin >> role;
        try {
                add = searchByID(id);
            }
        catch (exception& e){
            cout<<e.what()<<endl;
            continue;
        }
        try{
            add = isValidpoliticiandetails(id, power, bloc, role);
        }
        catch (exception& e){
            cout<<e.what()<<endl;
            continue;
        }
    }
    int ID = stoi(id);
    int POWER = stoi(power);
    Politician* poli = addpolitician(first_name,last_name, ID, POWER,role,bloc);
    this->addNewPoliticianToParty(poli);
    update_biggest_Party();
    return add;
}

bool PoliticalSys::isValidpoliticiandetails(string id, string power, string bloc, string role) {
    bool valid = true;
//    bool poli = searchByID(id);
    int pow = power.length();
    for (int i = 0; i < pow; i++) {
        if (isdigit(power[i]) == false) {//check if the id is number
            valid =false;
            break;
        }
    }
    int power1 = stoi(power);
    if(power1 < 0){
        valid=false;
    }
    if((bloc.compare("D")!= 0)&&(bloc.compare("R")!= 0)){
        valid= false;
    }
    if((role.compare("L")!= 0)&&(role.compare("S")!= 0)){
        valid=false;
    }
    if(!valid){
        throw invalidDetails();
    }
    return valid;
}

bool PoliticalSys::searchByID(string ids) {
    int len = ids.length();
    for (int i = 0; i < len; i++) {
        if (isdigit(ids[i]) == false) {//check if the id is number
            throw invalidID();
        }
    }
    int id = stoi(ids);
    if (id < 0) {
        throw invalidID();
    }
    Politician* found= nullptr;
    vector<Politician*>::iterator it;
    for( it = this->politicians_list.begin(); it != this->politicians_list.end();it++){
        if((*it)->getId()==id){
            found=(*it);
            break;
        }
    }
    if(found != nullptr){
        throw invalidID();
    }
    return true;
}

bool PoliticalSys::addParty() {
    bool add = false;
    string party_name;
    string politic_bloc;
    cout << "---Create Party---" << endl;
    while(!add) {
        cout << "Name:" << endl;
        cin >> party_name;
        cout << "Republican or Democratic party" << endl;
        cin >> politic_bloc;
        try {
                this->searchPartyByName(party_name);
            }
        catch (exception &e) {
            cout << e.what() << endl;
            continue;
        }
        try {
            isValidPartydetails(party_name, politic_bloc);
            }
        catch (exception &e) {
            cout << e.what() << endl;
             continue;
        }
        add = true;
    }
    this->addParty(party_name,politic_bloc);
    update_biggest_Party();
    return add;
}

bool PoliticalSys::searchPartyByName(string party_name) {
    bool good = true;
    vector<Party*>::iterator it;
    for( it = this->party_list.begin(); it != this->party_list.end();it++){
        if((*it)->getParty_name()==party_name){
//            good = false;
            throw invalidName();
        }
    }

    return good;
}

bool PoliticalSys::isValidPartydetails(string name, string bloc) {
    bool valid= true;
    if(((bloc.compare("R"))!=0)&&(((bloc).compare("D")!=0))){
        valid= false;
    }
    if(!searchPartyByName(name)){
        valid=false;
    }
    if(!valid){
        throw  invalidDetails();
    }
    return valid;
}


Party *PoliticalSys::addParty(string name1, string bloc) {
    Party *add_party;
    if ((bloc.compare("R") == 0)) {
        add_party = new RepublicParty(name1);
        this->party_list.push_back(add_party);
        vector<Politician*>::iterator it;
        for( it = this->politicians_list.begin(); it != this->politicians_list.end();it++){
            if((*it)->getParty()== nullptr){
                add_party->addPoliticianToParty((*it));
            }
            else{
                if(add_party->getPartySize() < (*it)->getParty()->getPartySize()){
                    add_party->addPoliticianToParty(*it);
                }
            }
        }
    }
    else{//it is democratic party
        add_party = new DemocraticParty(name1);
        this->party_list.push_back(add_party);//push new list and insert match politicians
        vector<Politician*>::iterator it;
        for( it = this->politicians_list.begin(); it != this->politicians_list.end();it++){
            if((*it)->getParty()== nullptr){
                add_party->addPoliticianToParty(*it);
            }
            else{
                if(add_party->getPartySize() < (*it)->getParty()->getPartySize()){
                    add_party->addPoliticianToParty(*it);
                }
            }
        }
    }
    return add_party;
}

void PoliticalSys::update_biggest_Party() {
    int max = -1;
    Party *big;
    vector<Party*>::iterator it;
    for (it = this->party_list.begin(); it != this->party_list.end(); it++) {//big by number of party members
        if ((*it)->getPartySize() > max) {
            max = (*it)->getPartySize();
            big = (*it);
        }
        if((*it)->getPartySize() == max)
        {
            if(((*it)->getParty_name().compare(big->getParty_name())) > 0){//big by party name
            max = (*it)->getPartySize();
            big = (*it);
            }
        }
    }
    this->biggest = big;
}


bool PoliticalSys::removePolitician() {
    bool remove = false;
    string id;
    Politician *poli;
    cout << "---Remove Politician---" << endl;
    while(!remove) {
        cout << "Enter the ID:" << endl;
        cin >> id;

        try {
            poli = searchByIDtoRemove(id);
        }
        catch (exception& e){
            cout<<e.what()<<endl;
            continue;
        }
        if (this->politicians_list.size() == 0) {
            return remove;
        }
        else {
            remove = true;
        }
    }
    if(poli->getParty()!= nullptr) {
        remove = poli->getParty()->removePoliticianFromParty(poli);
    }
    vector<Politician*>::iterator it;
    for( it = this->politicians_list.begin(); it != this->politicians_list.end();it++) {
        if ((*it)->getId() == poli->getId()) {
            break;
        }
    }
    this->politicians_list.erase(it);
    delete(poli);
    update_biggest_Party();
    return remove;
}

Politician* PoliticalSys::searchByIDtoRemove(string ids) {
    int len = ids.length();
    for (int i = 0; i < len; i++) {
        if (isdigit(ids[i]) == false) {//check if the id is number
            throw invalidID();
        }
    }
    int id = stoi(ids);
    if (id < 0) {
        throw invalidID();
    }
    Politician* found= nullptr;
    vector<Politician*>::iterator it;
    for( it = this->politicians_list.begin(); it != this->politicians_list.end();it++){
        if((*it)->getId()==id){
            found=(*it);
            break;
        }
    }
    if(found == nullptr){
        throw invalidID();
    }
    return found;
}



bool PoliticalSys::removeParty() {
    bool remove = false;
    string party_name;
    Party* party;
    if (this->party_list.size() == 0){
        return false;
    }
    cout << "---Remove Party---" << endl;
    while(remove == false) {
        cout << "Enter party name:" << endl;
        cin >> party_name;
        try {
            party = searchPartyByNameToRemove(party_name);
            }
        catch (exception &e) {
            cout << e.what() << endl;
            continue;
        }
        remove = true;
    }
    removeParty(party);
    update_biggest_Party();
    return remove;
}

Party *PoliticalSys::searchPartyByNameToRemove(string party_name) {
    Party* party;
    vector<Party*>::iterator it;
    for( it = this->party_list.begin(); it != this->party_list.end();it++){
        if((*it)->getParty_name()==party_name){
            party= (*it);
            return party;
        }
    }
    throw invalidName();
}

void PoliticalSys::removeParty(Party* party) {
    vector<Politician*> politicianNoParty = party->getPattyMembers();
    vector<Party*>::iterator it;
    for( it = this->party_list.begin(); it != this->party_list.end();it++) {
        if ((*it)->getParty_name() == party->getParty_name()) {
            break;
        }
    }
    this->party_list.erase(it);
    delete(party);
    vector<Politician *>::iterator it1;
    for (it1 = politicianNoParty.begin(); it1 != politicianNoParty.end(); it1++) {
        (*it1)->setPartyToMember(nullptr);
        (*it1)->updateChairman(nullptr);
    }
    for (it1 = politicianNoParty.begin(); it1 != politicianNoParty.end(); it1++) {
        addNewPoliticianToParty((*it1));
    }

}


void PoliticalSys::elections() {
    int emptyParties =0;
    if(this->party_list.size()==0 || this->politicians_list.size()==0){
        return;
    }
    cout << "----Primaries----" << endl;
    vector<Party*>::iterator it;
    for(it = this->party_list.begin(); it != this->party_list.end(); it++){
        if((*it)->getPartySize()!=0){
            (*it)->primaries();
        }
        else{
            emptyParties++;
        }
    }
    if(emptyParties==this->party_list.size()){
        return;
    }
    cout << "----Elections----" << endl;
    for(it = this->party_list.begin(); it != this->party_list.end(); it++) {
        cout<<"Party: "<<(*it)->getParty_name()<<",Power: "<<(*it)->powerCalculate()<<endl;
    }
    Party* winner = this->elctionsWinner();
    cout<<"----Elections Results----" << endl;
    cout<<winner->getParty_name()<<" party won the elections and "<<winner->getParty_chairman()<<" is the prime minister"<<endl;
}

Party *PoliticalSys::elctionsWinner() {
    int max_power =-1;
    Party* winner;
    vector<Party*>::iterator it;
    for(it = this->party_list.begin(); it != this->party_list.end(); it++){
       if((*it)->powerCalculate()> max_power){
           max_power=(*it)->powerCalculate();
           winner=(*it);
       }
    }
    return winner;
}


bool PoliticalSys::printPoliticians() {
    if(this->politicians_list.size()==0){
        return false;
    }
    cout<<"----Politicians----"<<endl;
    vector<Politician*>::iterator it;
    for(it = this->politicians_list.begin(); it != this->politicians_list.end(); it++) {
        (*it)->PrintPolitician();
    }
    return true;
}


bool PoliticalSys::printParties() {
    if(this->party_list.size()==0){
        return false;
    }
    cout<<"----Parties----"<<endl;
    vector<Party*>::iterator it;
    for(it = this->party_list.begin(); it != this->party_list.end(); it++) {
        (*it)->printParty();
    }
    return true;
}


void PoliticalSys::BiggestParty() {
    if(this->party_list.size()==0){
        return;
    }
    cout<<"----Biggest Party----"<<endl;
    cout<<"["<< this->biggest->getParty_name()<<","<<this->biggest->getPartySize()<<"]"<<endl;
}


PoliticalSys::~PoliticalSys() {

    vector<Politician*>::iterator it_;
    for(it_ = this->politicians_list.begin(); it_ != this->politicians_list.end(); it_++) {
        delete(*it_);
    }
    vector<Party*>::iterator it;
    for(it = this->party_list.begin(); it != this->party_list.end(); it++) {
        delete(*it);
    }
}