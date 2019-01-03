//
// Created by Adam Stelmaszyk on 30/12/2018.
//

#include "Customer.h"
Customer::Customer(int i, int x, int y, int d, int s, int e, int u, bool und) :
        id(i), x_pos(x), y_pos(y), demand(d), start(s), end(e), unload(u), undelivered(und) {
}

double Customer::distance(Customer* p)
{
    return sqrt(pow(p->x_pos - this->x_pos, 2) + pow(p->y_pos - this->y_pos, 2));
}