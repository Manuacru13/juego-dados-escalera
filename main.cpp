#include <iostream>
#include <ctime>
#include "menu.h"
#include "rlutil.h"
#include "interfaz.h"


int main()
{
    srand(time(0));

    animacionPresentacion();

    opcionMenu();

    return 0;
}

