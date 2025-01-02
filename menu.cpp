#include <iostream>
#include <cstdlib>
#include "rlutil.h"
#include "simulacion.h"
#include "unJugador.h"
#include "interfaz.h"
#include "funciones.h"

using namespace std;


void opcionMenu(){
    int y = 0, opcion = 1;
    bool prueba;
    int puntaje;
    string nombres[3];
    int tablaPuntajes[3]={0};

    string nombre;

    rlutil::hidecursor();
    rlutil::saveDefaultColor();

    do{
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        seleccionar("UN JUGADOR", 50, 16, y == 0);
        seleccionar("MOSTRAR PUNTUACION MAS ALTA", 50, 17, y == 1);
        seleccionar("MODO SIMULACION", 50, 18, y == 2);
        seleccionar("SALIR DEL JUEGO", 50, 19, y == 3);

        switch(rlutil::getkey()){
            case rlutil::KEY_UP:
                y--;
                if(y<0) y=0;
                break;

            case rlutil::KEY_DOWN:
                y++;
                if(y>3) y=3;
                break;

            case rlutil::KEY_ENTER:

                switch(y){
                    case 0:
                        prueba = false;
                        rlutil::cls();
                        unJugador(prueba,nombre,puntaje);
                        cargarPuntajes(nombre, puntaje, nombres, tablaPuntajes);
                        break;
                    case 1:
                        rlutil::cls();
                        mostrarPuntajes(nombres, tablaPuntajes);
                        break;
                    case 2:
                        prueba = true;
                        rlutil::cls();
                        modoSimulacion(prueba,nombre,puntaje);
                        ///cargarPuntajes(nombre, puntaje, nombres, tablaPuntajes);
                        break;
                    case 3:
                        opcion = 0;
                        rlutil::cls();
                        cout<<"GRACIAS POR JUGAR A ESCALERA :-)"<<endl;
                        break;
            }
        }
    }while(opcion!=0);
}

