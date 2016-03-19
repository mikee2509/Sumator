#include "main.h"

using namespace std;

int main()
{
    Cyfra nowa(8,16);
    Cyfra druga(7,16);
    Cyfra jakas = nowa+druga;

    jakas.showDigit();
    jakas.showBase();
    jakas.showCarry();


    return 0;
}
