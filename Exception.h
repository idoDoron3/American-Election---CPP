//
// Created by ido on 1/14/23.
//

#ifndef AMERICANELECTIONS_EXCEPTION_H
#define AMERICANELECTIONS_EXCEPTION_H
#include <exception>
using namespace std;

class invalidID : public exception{
public:
    /* inputs:
    *
    * return: error message when input id is not valid */
    virtual const char* what( ) const throw( ){
        return "Please enter valid id";
    }
};
class invalidName : public exception{
public:
    /* inputs:
    *
    * return: error message when input name is not valid */
    virtual const char* what( ) const throw( ){
        return "Please enter valid name";
    }
};

class invalidDetails : public exception{
public:
    /* inputs:
    *
    * return: error message when input details is not valid */
    virtual const char* what( ) const throw( ){
        return "Please enter valid details";
    }
};
#endif //AMERICANELECTIONS_EXCEPTION_H
