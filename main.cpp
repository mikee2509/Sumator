#include "main.h"

using namespace std;

int main()
{
    Cyfra jeden(1,15);
    Cyfra dwa(2,16);
    Cyfra trzy(3, 16);
    Liczba jakas(16, 5, -1, 6, 34, 15, 1);
    jakas.showNumber();
    cout << endl;
    jakas.showBase();


    return 0;
}
