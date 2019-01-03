#include <iostream>
#include <list>
#include <time.h>
#include "Problem.h"

int main(int argc, char* argv[]) {
    //0026_C101
    // rc21010
    //cvrptw4
    //m2kvrptw-0.txt

    //char* plik = "/Users/adamstelmaszyk/clion_project/kiedys_trzeba_to_zrobic/rc21010.txt";
    //double the_best_result = 1e100;
    int the_best_routs = 2147483640;
    double the_best_time = 1e100;
    vector<string> lista_wyrazow;

    //while (1 > suma) {
    Problem input;
    if (!input.load(argv[1])) {
        puts("-1");
        return 1;
    }

    input.pierwszeRozwiazanie();
    return 0;
}