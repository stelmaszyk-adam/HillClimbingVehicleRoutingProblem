//
// Created by Adam Stelmaszyk on 30/12/2018.
//

#ifndef TEN_ALGORYTM_BEDZIE_DZIALAL_VEHICLE_H
#define TEN_ALGORYTM_BEDZIE_DZIALAL_VEHICLE_H


#include "Problem.h"
#include "Customer.h"
#include "Trasa.h"
#include <vector>

class Customer;

class Vehicle {
public:
    Vehicle();
    std::vector<Customer*> ListaKlientow;
    int id;
    double weight = 0;
    double time = 0;
    double distance = 0;
    bool jestPelny = false;

    bool dodaj_do_auta(Customer* customer);
    void koniec_dodaj_ostatnia_trase();
};


#endif //TEN_ALGORYTM_BEDZIE_DZIALAL_VEHICLE_H
