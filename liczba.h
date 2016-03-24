#ifndef LICZBA_H
#define LICZBA_H
#include "main.h"
using namespace std;

class Cyfra;

//! Class representing a number.
/*! Liczba object consists of a vector of Cyfra objects. */
class Liczba
{
    unsigned char base; //!< Base in which the number is represented.
    vector<Cyfra> number; //!< Vector of digits in the same base.
    Liczba addZeroesToFront(int howMany); //!< Method for adding leading zeroes to the number.
    Liczba addZeroesToFront(Liczba &original, int howMany); //!< Method for adding leading zeroes to the number.
    Liczba killLeadingZeroes(); //!< Get rid of leading zeroes in the number.
    Liczba killLeadingZeroes(Liczba &original); //!< Get rid of leading zeroes in the number.

public:
    //! Function constructing a new Liczba object.
    /*! The constructor enables to fill the new object's number vector with as many digits as needed.
        \param baza : base in which number is to be represented
        \param n : number of *additional* parameters used for digits' input */
    Liczba(unsigned char baza, int n=0, ...);

    void showBase() { cout << "Baza: " << static_cast<short>(base) << endl;} //!< Print number's base on the screen.
    void showNumber(); //!< Print the number on the screen.

    void setNumber(long num, unsigned char baza); //!< Change the number stored in object. \param num : new number \param baza : new base
    void setNumberL(long long num, unsigned char baza); //!< Change the number stored in object. \param num : new number \param baza : new base

    unsigned char getBase() { return base; } //!< Access the base value.

    //! *+* operator overload.
    /*! Both Liczba objects must have the same *base* otherwise the function returns an empty Liczba object.
        The function uses Cyfra's *+* operator overload to add the two numbers.
        \see Cyfra::operator+(Cyfra &q)
        \return A new Liczba object with a sum of the two numbers.*/
    Liczba operator+(Liczba &q);

    string toString(); //!< Convert the number to string.
                       /*!< \return A string with the object's number. */
    long toLong(); //!< Convert the number to long integer
    long long toLongLong(); //!< Convert the number to long long integer
    Cyfra* ptrDigitOfNumber(unsigned int thisOne); //!< Access a digit of the number. \return A pointer to the digit.
    Cyfra getDigitOfNumber(unsigned int thisOne); //!< Access a digit of the number. \return A copy of Cyfra object stored in the vector.
};

#endif // LICZBA_H
