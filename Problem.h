//
// Created by Adam Stelmaszyk on 30/12/2018.
//

#ifndef TEN_ALGORYTM_BEDZIE_DZIALAL_PROBLEM_H
#define TEN_ALGORYTM_BEDZIE_DZIALAL_PROBLEM_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <functional>
#include <list>
#include "Customer.h"
#include "Vehicle.h"
#include "Solution.h"


using namespace std;

class Problem{
public:
    static list<Customer*> allCustomer;
    static Customer* magazyn;
    static double** distances;
    int ilosc_ciezarowek;
    static int capacity;


    bool load (char *filename);
    int calDistance();
    void pierwszeRozwiazanie();

    struct pfih_comparator
    {
        inline bool operator()  (const std::pair<Customer*, double>& inst1, std::pair<Customer*, double>& inst2){
            return inst1.second < inst2.second;
        }
    };

};


#endif //TEN_ALGORYTM_BEDZIE_DZIALAL_PROBLEM_H
