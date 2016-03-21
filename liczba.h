#ifndef LICZBA_H
#define LICZBA_H
#include "main.h"
using namespace std;

class Cyfra;

class Liczba
{
    unsigned char base;
    vector<Cyfra> number;
    Liczba addZeroesToFront(int howMany);
    Liczba addZeroesToFront(Liczba &original, int howMany);
    Liczba killLeadingZeroes();
    Liczba killLeadingZeroes(Liczba &original);

public:
    Liczba(unsigned char baza, int n=0, ...);
    void setBase(const unsigned char baza) { base = baza; }
    void showBase() { cout << "Baza: " << static_cast<short>(base) << endl;}
    void showNumber();
    unsigned char getBase() { return base; }
    Liczba operator+(Liczba &q);

//  long toLong();
//  void saveLong(const long liczba);
//  void saveLong(const long liczba, const unsigned char baza);
};

#endif // LICZBA_H
