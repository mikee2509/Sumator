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
    void showBase() { cout << "Baza: " << static_cast<short>(base) << endl;}
    void showNumber();
    void setNumber(long num, unsigned char baza);
    void setNumberL(long long num, unsigned char baza);
    unsigned char getBase() { return base; }
    Liczba operator+(Liczba &q);
    string toString();
    long toLong();
    long long toLongLong();
    Cyfra* ptrDigitOfNumber(unsigned int thisOne);
    Cyfra getDigitOfNumber(unsigned int thisOne);
};

#endif // LICZBA_H
