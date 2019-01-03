//
// Created by Adam Stelmaszyk on 30/12/2018.
//

#ifndef TEN_ALGORYTM_BEDZIE_DZIALAL_TRASA_H
#define TEN_ALGORYTM_BEDZIE_DZIALAL_TRASA_H


#include "Customer.h"
#include "Problem.h"
#include <list>

using namespace std;

class Trasa {
public:
    list<Customer*> klienci;
    Trasa();

    void dodajKlienta(Customer* customer1);
    void wyjazdZeStora(Customer* customer);
    void powrotDoStora();
    //void dodajKlenta(Customer* customer1);

    double time = 0;
    double distance = 0;
    int cargo = 0;

};


#endif //TEN_ALGORYTM_BEDZIE_DZIALAL_TRASA_H
