//
// Created by Adam Stelmaszyk on 30/12/2018.
//

#ifndef TEN_ALGORYTM_BEDZIE_DZIALAL_SOLUTION_H
#define TEN_ALGORYTM_BEDZIE_DZIALAL_SOLUTION_H

#include <iostream>
#include <list>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "Customer.h"
#include "Vehicle.h"

class Customer;
class Vehicle;

class Solution {
public:

    std::vector<Vehicle*> vehicles;
    void laczenieTras();
    void czasOgolny();

};


#endif //TEN_ALGORYTM_BEDZIE_DZIALAL_SOLUTION_H
