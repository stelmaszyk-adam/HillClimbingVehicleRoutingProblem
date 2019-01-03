//
// Created by Adam Stelmaszyk on 30/12/2018.
//

#include "Trasa.h"
Trasa::Trasa() {}



void Trasa::dodajKlienta(Customer *customer1) {
    customer1->undelivered = true;
    cargo = cargo + customer1->demand;
    distance = distance + customer1->distance(klienci.back());
    time = time + customer1->distance(klienci.back());
    if(time < customer1->start){
        time = customer1->start;
    }
    time = time + customer1->unload;
    klienci.push_back(customer1);
}

void Trasa::wyjazdZeStora(Customer *customer) {
    customer->undelivered = true;
    cargo = cargo + customer->demand;
    distance = distance + customer->distance(Problem::magazyn);
    time = time + customer->distance(Problem::magazyn);
    if(time < customer->start){
        time = customer->start;
    }
    time = time + customer->unload;
    klienci.push_back(customer);

}

void Trasa::powrotDoStora() {
    distance = distance + klienci.back()->distance(Problem::magazyn);
    time = time + klienci.back()->distance(Problem::magazyn);
}
