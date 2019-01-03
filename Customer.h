//
// Created by Adam Stelmaszyk on 30/12/2018.
//

#ifndef TEN_ALGORYTM_BEDZIE_DZIALAL_CUSTOMER_H
#define TEN_ALGORYTM_BEDZIE_DZIALAL_CUSTOMER_H
#include <cmath>

class Customer {
public:
    Customer(){};
    Customer(int id, int x, int y, int demand, int start, int end, int unload, bool undelivered);
    double distance(Customer* p);
    int id;
    double x_pos, y_pos;
    int demand, start, end, unload;
    bool undelivered;


};


#endif //TEN_ALGORYTM_BEDZIE_DZIALAL_CUSTOMER_H
