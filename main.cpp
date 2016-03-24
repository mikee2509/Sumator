#include "main.h"
/*! \mainpage Project 1 documentation
 *  \section Sumator
 *    Sumator enables you to add numbers in any base from 2 to 255.
 * \author Michal Sieczkowski
 * \date March 2016
 */
using namespace std;

int main(int argc, char* argv[])
{
    Liczba jakas(240, 6, 8, 5, 235, 89, 103, 155);
    jakas.showNumber();
    cout << endl << jakas.toLongLong();
    nl();

    Liczba druga(240, 4, 239, 84, 132, 135);
    druga.showNumber();
    cout << endl << druga.toLongLong();
    nl();

    Liczba trzecia = jakas+druga;
    trzecia.showNumber();
    cout << endl << "Longlong: " << trzecia.toLongLong();
    cout << endl << "String: " <<  trzecia.toString();
    nl();
    nl();

    Liczba nowa(16, 3, 15, 8, 5);
    nowa.showBase();
    nowa.showNumber();
    nl();

    nowa.setNumberL(1234254, 55);
    nowa.showBase();
    nowa.showNumber();
	nl();
    return 0;
}

void nl()
{
    cout << endl << endl;
}
