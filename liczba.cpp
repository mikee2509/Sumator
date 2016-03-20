#include "liczba.h"

Liczba::Liczba(unsigned char baza, int n, ...)
{
    if(baza<2) {
        base=2;
        cout << "Minimalna baza to 2 (ustawiono base=2)" << endl;
    }
    else base = baza;

    int j=n;
    int temp;
    va_list ap;
    va_start(ap, n);
    while(n-- >0)
    {
        temp = va_arg(ap, int);
        if(temp>=base || temp<0) {
            cout << "Popraw " << j-n+2 << " argument w wywolaniu konstruktora (zastapiono zerem)" << endl;
            number.push_back(Cyfra(0, base));
        }
        else number.push_back(Cyfra(static_cast<unsigned char>(temp), base));
    }
    va_end(ap);
}

void Liczba::showNumber()
{
    vector<Cyfra>::iterator i;
    for(i=number.begin(); i!=number.end(); i++)
    {
        cout << static_cast<short>(i->getDigit()) << " ";
    }
}
