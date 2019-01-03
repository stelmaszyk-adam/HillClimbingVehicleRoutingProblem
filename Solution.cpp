//
// Created by Adam Stelmaszyk on 30/12/2018.
//

#include "Solution.h"

void Solution::laczenieTras(){

    std::srand (time(NULL));
    if(vehicles.size()<2){
        return;
    }

    int v1 = rand() % vehicles.size();
    int v2;
    do{
       v2 = rand() % vehicles.size();
    }while(v2==v1);
    vector <Customer*> listaKlientowNowa;

    for(auto client : vehicles[v1]->ListaKlientow){
        client->undelivered = false;
        listaKlientowNowa.push_back(client);
    }
    for(auto client : vehicles[v2]->ListaKlientow){
        client->undelivered = false;
        listaKlientowNowa.push_back(client);
    }
    double czas1 = vehicles[v1]->time;
    double czas2 = vehicles[v2]->time;

    double czasRazem = czas1 + czas2;

    Vehicle* nowyPojazd1 = new Vehicle();
    Vehicle* nowyPojazd2 = new Vehicle();

    int i=1, d;
    double timePrzykladowy;
    while(i!=0){
        i = 0;
        d = 0;
        timePrzykladowy = 1e100;
        Customer *ktoregoTrzebaDodac;
        Vehicle przyklad;
        Vehicle* DodawanaCiezarowka;

        if(nowyPojazd1->jestPelny && !nowyPojazd2->jestPelny){
            //cout<<"Weszlo tuta1" <<endl;
            DodawanaCiezarowka = nowyPojazd2;
        } else if(nowyPojazd2->jestPelny) {
            //cout<<"Weszlo tuta" <<endl;
            for(auto client : vehicles[v1]->ListaKlientow){
                client->undelivered = true;
            }
            for(auto client : vehicles[v2]->ListaKlientow){
                client->undelivered = true;
            }
            return;
        }
        else{
            DodawanaCiezarowka = nowyPojazd1;
        }
        for(auto klient : listaKlientowNowa){
            przyklad = (*DodawanaCiezarowka);
            if(klient->undelivered){
                continue;
            }
            i++;
            if(przyklad.dodaj_do_auta(klient)){
                d++;
            } else{
                continue;
            }
            if(timePrzykladowy > przyklad.time){
                timePrzykladowy = przyklad.time;
                ktoregoTrzebaDodac = klient;
            }
        }
        if(d==0){
            //cout<<"KOniec dodaj do trasy"<<endl;
            DodawanaCiezarowka->koniec_dodaj_ostatnia_trase();
            continue;
        }
        if(i==0){
            break;
        }
        DodawanaCiezarowka->dodaj_do_auta(ktoregoTrzebaDodac);
        ktoregoTrzebaDodac->undelivered = true;
    }

    double czasPo;
    czasPo = nowyPojazd1->time + nowyPojazd2->time;
    /*cout<<"Czas Razem: "<<czasRazem<<endl;
    cout<<"Czas Po: "<<czasPo<<endl;
    cout<<"Jakie zmienia: "<<v1<<" "<<v2<<endl;*/


    if(czasPo < czasRazem){
        //cout<<"czy tutaj weszlo"<<endl;
        if(nowyPojazd2->ListaKlientow.empty())
        {
            //cout<<"czy tutaj weszlo1"<<endl;
            vehicles[v1] = nowyPojazd1;
            vehicles.erase(vehicles.begin() + v2);
        } else{
            //cout<<"czy tutaj weszlo2"<<endl;

            vehicles[v2] = nowyPojazd2;
            vehicles[v1] = nowyPojazd1;
        }
    }



}

void Solution::czasOgolny() {
    double czas_calkowity = 0;
    cout.precision(16);
    for(auto vehicle : vehicles){
        czas_calkowity = czas_calkowity + vehicle->time;
    }
    cout<<vehicles.size()<<" "<<czas_calkowity<<endl;
    for(auto vehicle : vehicles){
        for(auto custom : vehicle->ListaKlientow){
            cout<<custom->id<<" ";
        }
        cout<<endl;
    }

}
