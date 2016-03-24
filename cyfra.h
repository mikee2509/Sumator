#ifndef CYFRA_H
#define CYFRA_H
#include "main.h"
using namespace std;

class Liczba;


/*!\brief Class representing a single digit. */
class Cyfra
{
    unsigned char digit; //!< Digit value.
    unsigned char base; //!< Base in which the digit is represented.
    bool carry; //!< Variable holding info whether a digit has carry or not.
                /*!< The state of carry variable can be positie as a result of addition. */

public:
    //! Function constructing a new Cyfra object.
    /*! The constructor takes at least 2 arguments:
        \param num : value of the digit
        \param baza : base in which the digit is represented
        \param prz : *optional* value of carry (false by default) */
    Cyfra(unsigned char num, unsigned char baza, bool prz=false);


    void setDigit(unsigned char num); //!< Change digit's value
                                      /*!< The value of num must be lower than current base. */
    void setBase(unsigned char baza); //!< Change digit's base
                                      /*!< Parameter baza must be bigger than digit's value */
	void setCarry(bool prz) { carry = prz; } //!< Switch digit's carry state.


    void showDigit() { cout << "Cyfra:  " << static_cast<short>(digit) << endl; } //!< Print digit's value on the screen.
    void showBase() { cout << "Baza: " << static_cast<short>(base) << endl; } //!< Print digit's base on the screen.
    void showCarry() { cout << "Przeniesienie: " << carry << endl; } //!< Print digit's carry on the screen.


    unsigned char getDigit() { return digit; } //!< Returns digit's value.
    unsigned char getBase() { return base; } //!< Returns digit's base.
    bool getCarry() { return carry; } //!< Returns digit's carry.


    //! *+* operator overload.
    /*! Both Cyfra objects must have the same *base* otherwise the function returns Cyfra(0,2,0).
        If the sum of digits is higher than *base* the carry value of returned object is set to *true*.*/
    Cyfra operator+(Cyfra &q);
};

#endif // CYFRA_H
