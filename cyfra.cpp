#include "cyfra.h"

Cyfra::Cyfra(unsigned char num, unsigned char baza, bool prz)
{
    if(baza<2 && num==0)
    {
        cout << "UWAGA! Minimalna baza to 2. (Ustawiono base = 2)" << endl;
        base = 2;
        digit = 0;
    }
    else if(num==255)
    {
        cout << "UWAGA! Maksymalna cyfra to 254. (Ustawiono digit = 254, base = 255)" << endl;
        base = 255;
        digit = 254;
    }
    else if(baza<=num)
    {
        cout << "UWAGA! Baza przekazana w argumencie mniejsza lub rowna cyfrze. (Ustawiono base = " << num+1 << ")" << endl;
        base = num+1;
        digit = num;
    }
    else
    {
        base = baza;
        digit = num;
    }
    carry = prz;
}

void Cyfra::setDigit(unsigned char num)
{
    if(num<base) digit=num;
    else cout << "UWAGA! Cyfra nie nalezy do bazy (" << static_cast<short> (base) << ")." << endl;
}

void Cyfra::setBase(unsigned char baza)
{
    if(baza>digit) base=baza;
    else cout << "UWAGA! Za niska baza." << endl;
}

Cyfra Cyfra::operator+(Cyfra &q)
{
    if(base!=q.base)
    {
        cout << "UWAGA! Niezgodne bazy." << endl;
        return Cyfra(0,2,0);
    }
    bool newCarry = carry || q.carry;
    unsigned char newDigit = (digit + q.digit) % base;
    if((digit+q.digit) >= base) newCarry = true;

    return Cyfra(newDigit, base, newCarry);
}

