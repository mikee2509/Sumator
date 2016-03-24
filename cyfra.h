#ifndef CYFRA_H
#define CYFRA_H
#include "main.h"
using namespace std;

class Liczba;

class Cyfra
{
    unsigned char digit;
    unsigned char base;
    bool carry;

public:
    Cyfra(unsigned char num, unsigned char baza, bool prz=false);

    void setDigit(unsigned char num);
    void setBase(unsigned char baza);
	void setCarry(bool prz) { carry = prz; }

    void showDigit() { cout << "Cyfra:  " << static_cast<short>(digit) << endl; }
    void showBase() { cout << "Baza: " << static_cast<short>(base) << endl; }
    void showCarry() { cout << "Przeniesienie: " << carry << endl; }

    unsigned char getDigit() { return digit; }
    unsigned char getBase() { return base; }
    bool getCarry() { return carry; }

    Cyfra operator+(Cyfra &q);
};

#endif // CYFRA_H
