//
// Created by Adam Stelmaszyk on 30/12/2018.
//

#include "Vehicle.h"
Vehicle::Vehicle() {}

bool Vehicle::dodaj_do_auta(Customer* customer) {

    if(ListaKlientow.empty()){
        ListaKlientow.push_back(customer);
        time = customer->distance(Problem::magazyn);
        if(time < customer->start){
            time = customer->start;
        }
        time = customer->unload + time;
        weight = customer->demand + weight;
        //customer->undelivered = true;
        return true;
    } else{
        double czyBedzieMialCzasNaPowrot = time + customer->distance(ListaKlientow.back()) + customer->unload + customer->distance(Problem::magazyn);
        double DrogaDoPunktuZCzasem = time + customer->distance(ListaKlientow.back());
        if(czyBedzieMialCzasNaPowrot  < Problem::magazyn->end && DrogaDoPunktuZCzasem < customer->end ) {
            if(weight + customer->demand < Problem::capacity){
                if(DrogaDoPunktuZCzasem < customer->start){
                    DrogaDoPunktuZCzasem = customer->start;
                }
                ListaKlientow.push_back(customer);
                //customer->undelivered = true;
                weight = customer->demand + weight;
                time = DrogaDoPunktuZCzasem + customer->unload;
                return true;
            }
        }
    }
    return false;

}

void Vehicle::koniec_dodaj_ostatnia_trase(){
    time = time + ListaKlientow.back()->distance(Problem::magazyn);
    jestPelny = true;
}