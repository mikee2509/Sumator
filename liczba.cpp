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

void Liczba::setNumber(long num, unsigned char baza)
{
    base = baza;
    number.clear();

    int width=1;
    if(base>10 && base<=100) width=2;
    else if(base>100) width=3;

    stringstream ss;
    string numstr, choose;
    int i, temp;
    ss << num;
    ss >> numstr;
    ss.str(string());
    ss.clear();
    int length = numstr.size();
    for(i=length; i>0; i-=width)
    {
        if(i>width)
        {
            choose = numstr.substr(i-width, width);
            ss << choose;
            ss >> temp;
            ss.str(string());
            ss.clear();
            number.push_back(Cyfra(static_cast<unsigned char>(temp), base));
            numstr.erase(i-width, width);
        }
        else
        {
            ss << numstr;
            ss >> temp;
            ss.str(string());
            ss.clear();
            number.push_back(Cyfra(static_cast<unsigned char>(temp), base));
        }
    }
    reverse(number.begin(), number.end());
}

void Liczba::setNumberL(long long num, unsigned char baza)
{
    base = baza;
    number.clear();

    int width=1;
    if(base>10 && base<=100) width=2;
    else if(base>100) width=3;

    stringstream ss;
    string numstr, choose;
    int i, temp;
    ss << num;
    ss >> numstr;
    ss.str(string());
    ss.clear();
    int length = numstr.size();
    for(i=length; i>0; i-=width)
    {
        if(i>width)
        {
            choose = numstr.substr(i-width, width);
            ss << choose;
            ss >> temp;
            ss.str(string());
            ss.clear();
            number.push_back(Cyfra(static_cast<unsigned char>(temp), base));
            numstr.erase(i-width, width);
        }
        else
        {
            ss << numstr;
            ss >> temp;
            ss.str(string());
            ss.clear();
            number.push_back(Cyfra(static_cast<unsigned char>(temp), base));
        }
    }
    reverse(number.begin(), number.end());
}

Liczba Liczba::operator+(Liczba &q)
{
    if(base!=q.base)
    {
        cout << "UWAGA! Niezgodne bazy." << endl;
        return Liczba(base);
    }
    Liczba first = killLeadingZeroes();
    Liczba second = killLeadingZeroes(q);

    int sizeDiff = first.number.size() - second.number.size();

    if(sizeDiff > 0)
		second = addZeroesToFront(second, sizeDiff);
	else if(sizeDiff < 0)
		first = addZeroesToFront(first, -sizeDiff);


    Liczba nowa(base);
    vector<Cyfra>::iterator i, j, k;
    for(i=k=first.number.end()-1, j=second.number.end()-1; i>=first.number.begin(); i--, j--)
    {
        if(i==k || nowa.number.back().getCarry() == false)
            nowa.number.push_back(*i+*j);
        else
            nowa.number.push_back(Cyfra(1,base)+*i+*j);
    }
    if(nowa.number.back().getCarry()) nowa.number.push_back(Cyfra(1,base));
    reverse(nowa.number.begin(), nowa.number.end());
    return nowa;
}

Liczba Liczba::addZeroesToFront(int howMany)
{
    Liczba nowa(base);
    for(int j=0; j<howMany; j++)
        nowa.number.push_back(Cyfra(0,base));

    vector<Cyfra>::iterator i;
    for(i=number.begin(); i<number.end(); i++)
        nowa.number.push_back(*i);

    return nowa;
}

Liczba Liczba::addZeroesToFront(Liczba &original, int howMany)
{
    Liczba nowa(original.base);
    for(int j=0; j<howMany; j++)
        nowa.number.push_back(Cyfra(0,original.base));

    vector<Cyfra>::iterator i;
    for(i=original.number.begin(); i<original.number.end(); i++)
        nowa.number.push_back(*i);

    return nowa;
}

Liczba Liczba::killLeadingZeroes()
{
    Liczba nowa(base);
    vector<Cyfra>::iterator i;
    bool endOfZeroes=0;
    for(i=number.begin(); i<number.end(); i++)
    {
        if(i->getDigit() || endOfZeroes)
        {
            nowa.number.push_back(*i);
            endOfZeroes=1;
        }
    }
    return nowa;
}

Liczba Liczba::killLeadingZeroes(Liczba &original)
{
    Liczba nowa(original.base);
    vector<Cyfra>::iterator i;
    bool endOfZeroes=0;
    for(i=original.number.begin(); i<original.number.end(); i++)
    {
        if(i->getDigit() || endOfZeroes)
        {
            nowa.number.push_back(*i);
            endOfZeroes=1;
        }
    }
    return nowa;
}

string Liczba::toString()
{
    int width=1;
    if(base>10 && base<=100) width=2;
    else if(base>100) width=3;

    stringstream ss;
    string str;
    vector<Cyfra>::iterator i;
    for(i=number.begin(); i!=number.end(); i++)
        ss << setfill('0') << setw(width) << static_cast<int>(i->getDigit());
    ss >> str;
    return str;
}

long Liczba::toLong()
{
    long wynik = strtol(toString().c_str(), NULL, 10);
    return wynik;
}

long long Liczba::toLongLong()
{
    long long wynik = strtoll(toString().c_str(), NULL, 10);
    return wynik;
}

Cyfra* Liczba::ptrDigitOfNumber(int thisOne)
{
    return &number[thisOne];
}

Cyfra Liczba::getDigitOfNumber(int thisOne)
{
    return number[thisOne];
}
