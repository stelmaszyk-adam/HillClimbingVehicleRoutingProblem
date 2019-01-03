//
// Created by Adam Stelmaszyk on 30/12/2018.
//

#include "Problem.h"

//std::shared_ptr<VehicleState> Utils::origin;
std::list<Customer*> Problem::allCustomer;
double** Problem::distances;
Customer* Problem::magazyn;
int Problem::capacity;

bool Problem::load(char filename[]) {

    //liczenie ile jest linijek kodu
    string linia;
    int licznik = 0;
    bool czyContinue = false;
    fstream plik;
    plik.open(filename);
    while (getline(plik, linia))
    {
        czyContinue = false;
        for(int i=0; i<linia.size(); i++)
        {
            if(47<int(linia[i]) && 122> int(linia[i]))
            {
                licznik++;
                czyContinue = true;
                break;
            }
        }
        if(czyContinue)
        {
            continue;
        }
    }
    plik.close();

    char NieTekst[256];
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        return false;
    }

    for(int i=0; i<4; i++)
    {
        if(fscanf(fp, "%s", NieTekst) != 1)
        {
            return false;
        }
    }


    if( fscanf(fp, "%d", &ilosc_ciezarowek) != 1)
    {
        fclose(fp);
        return false;
    }
    if( fscanf(fp, "%d", &capacity) != 1)
    {
        fclose(fp);
        return false;
    }



    int inputNum=licznik-7;
    for(int i=0; i<12; i++)
    {
        if(fscanf(fp, "%s", NieTekst) != 1)
        {
            return false;
        }
    }

    //allCustomer.reserve(inputNum + 1);
    int totalDemand = 0;
    int endTime =0;
    for(int i = 0; i <= inputNum; ++i){
        double x, y;
        int d, s, e, u;

        if (i==0)
        {
            fscanf(fp, "%*d%lf%lf%d%d%d%d", &x, &y, &d, &s, &e, &u);
            totalDemand += d;
            endTime = e;
            allCustomer.push_back(new Customer(i, x, y, d, s, e, u, false));
            magazyn = *allCustomer.begin();
            continue;
        }

        if( fscanf(fp, "%*d%lf%lf%d%d%d%d", &x, &y, &d, &s, &e, &u) != 6){

            fclose(fp);
            return false;
        }

        if(endTime<s)
        {
            fclose(fp);
            return false;
        }
        totalDemand += d;
        //customer newCustomer(i, x, y, d, s, e, u, false);
        allCustomer.push_back(new Customer(i, x, y, d, s, e, u, false));
    }
    fclose(fp);

    distances = (double**)malloc(sizeof(double*) * allCustomer.size());
    for (int i = 0; i <allCustomer.size(); ++i)
    {
        distances[i] = (double*)malloc(sizeof(double) * allCustomer.size());
    }

    if(0==calDistance())
    {
        return false;
    }
    return true;
}




int Problem::calDistance()
{
    int x=0;
    for (Customer* point : Problem::allCustomer)
    {
        for (Customer* point2 : Problem::allCustomer)
        {
            Problem::distances[point->id][point2->id] = point->distance(point2);
            if(x==0 && distances[point->id][point2->id]>= point2->end)
            {
                return 0;
            }
        }
        x++;
    }
    return 1;
}

void Problem::pierwszeRozwiazanie() {
    std::vector<std::pair<Customer*, double>> points(allCustomer.size() - 1);
    auto it = allCustomer.begin();
    ++it;
    Customer* curr;
    double degreesdeposit = atan2(Problem::magazyn->y_pos, Problem::magazyn->x_pos) * (180.0 / 3.14);
    double newdegree = 0;
    while (it != allCustomer.end())
    {
        curr = *it;
        newdegree = atan2(curr->y_pos, curr->x_pos) * (180.0 / 3.14);
        double d = distances[0][curr->id];
        points[curr->id - 1] = std::pair<Customer*, double>(curr, (d * -0.7) + (0.1 * curr->demand) + (0.2 * (newdegree - degreesdeposit) / 360 * d));
        ++it;
    }

    std::sort(points.begin(), points.end(), pfih_comparator());
    Solution solution;
    Vehicle * v = new Vehicle();
    int tworzId = 0;
    v->id = tworzId;
    v->dodaj_do_auta(points[0].first);

    int ileZostalo = 0;
    while(true) {
        //cout<<"Ile razy tutaj weszlo"<<endl;
        for(auto it = ++points.begin(); it != points.end(); ++it){
            if((*it).first->undelivered){
                continue;
            }
            ileZostalo++;
            if(v->dodaj_do_auta((*it).first)){
                (*it).first->undelivered = true;
            }
        }

        if(ileZostalo == 0){

            break;
        }
        ileZostalo=0;
        v->koniec_dodaj_ostatnia_trase();
        solution.vehicles.push_back(v);

        //cout<<v->id<<" : "<<v->time<<endl;


        v = new Vehicle();
        tworzId++;
        v->id = tworzId;
    }
    //solution.czasOgolny();
    time_t start, end;
    int suma = 0;
    start = time(&start);


    while (300 > suma) {
        solution.laczenieTras();
        end = time(&end);
        suma = static_cast<int>(end - start);
    }

    cout<<endl<<endl;
    solution.czasOgolny();
}





