#ifndef LICZBA_H
#define LICZBA_H
#include "main.h"
using namespace std;

class Cyfra;

class Liczba
{
    unsigned char base;
    vector<Cyfra> number;

public:
    Liczba(unsigned char baza, int n=0, ...);
    void showBase() { cout << "Baza: " << static_cast<short>(base) << endl;}
    void showNumber();
    void setBase(const unsigned char baza) { base = baza; }
    unsigned char getBase() { return base; }

//        long toLong();
//        void saveLong(const long liczba);
//        void saveLong(const long liczba, const unsigned char baza);

};

#endif // LICZBA_H
