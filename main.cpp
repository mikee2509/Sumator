#include "main.h"

using namespace std;

int main()
{
    Liczba jakas(2, 6, 0, 0, 1, 0, 1, 1);
    jakas.showNumber();
    nl();
    Liczba druga(2, 4, 0, 1, 1, 1);
    druga.showNumber();
    nl();

    Liczba trzecia = jakas+druga;
    trzecia.showNumber();

    return 0;
}

void nl()
{
    cout << endl << endl;
}
