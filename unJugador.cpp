#include <iostream>
#include <cstdlib>
#include "rlutil.h"
#include "funciones.h"
#include "menu.h"
#include "interfaz.h"

using namespace std;

void unJugador(bool prueba, string &nombre, int &puntaje)
{

     int vDado[6];
    int puntos = 0, acuPuntos = 0;
    int contRondas = 0;
    int sumaPuntos = 0;
    int rondaMayor = 0;

    mostrarIntroduccion();  // Mostrar introduccion y esperar la tecla para comenzar

    rlutil::locate(45, 13);
    cout<<"Ingrese su nombre: ";
    cin>>nombre;

    do
    {
        contRondas++;
        for(int i=0; i<3; i++)
        {

            // Mostrar información de la ronda y puntos
            mostrarPuntosRonda(nombre, contRondas, i + 1, puntos, acuPuntos, rondaMayor);
            cout<<endl;

            rlutil::locate(42,14);
            cout<<"Presione una tecla para tirar dados.."<<endl;

            rlutil::anykey();

            tirarDados(prueba, vDado);

            puntos = puntosLanzamiento(vDado);

            rlutil::setColor(rlutil::LIGHTGREEN);
            rlutil::locate(47, 26);
            cout<<"Puntos del lanzamiento "<<i+1<<" :" <<puntos<<endl; ///Puntos del lanzamiento
            if (puntos == 100)
            {
                rlutil::setColor(rlutil::LIGHTGREEN);
                rlutil::locate(47, 24);
                cout<<"FELICITACIONES ES ESCALERA!!!"<<endl;
            }
            else switch (puntos)
                {
                case 10:
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    rlutil::locate(47, 24);
                    cout<<"GRAN TIRADA ES SEXTETO de 10!!!"<<endl;
                    sumaPuntos = puntos;
                    break;
                case 20:
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    rlutil::locate(47, 24);
                    cout<<"GRAN TIRADA ES SEXTETO de 20!!!"<<endl;
                    sumaPuntos = puntos;
                    break;
                case 30:
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    rlutil::locate(47, 24);
                    cout<<"GRAN TIRADA ES SEXTETO de 30!!!"<<endl;
                    sumaPuntos = puntos;
                    break;
                case 40:
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    rlutil::locate(47, 24);
                    cout<<"GRAN TIRADA ES SEXTETO de 6!!!"<<endl;
                    sumaPuntos = puntos;
                    //i=3; en caso para corta la ronda cuando sale "cero o sexteto de 6" y "cien o ESCALERA"
                    break;
                case 50:
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    rlutil::locate(47, 24);
                    cout<<"GRAN TIRADA ES SEXTETO de 5!!!"<<endl;
                    sumaPuntos = puntos;
                    break;
                case 60:
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    rlutil::locate(47, 24);
                    cout<<"GRAN TIRADA ES SEXTETO de 6!!!"<<endl;
                    sumaPuntos = puntos;
                    break;
                default:
                    sumaPuntos = puntos;
                }

            rlutil::anykey();

            if (puntos > rondaMayor)
            {
                rondaMayor = puntos;

            }
        }
        acuPuntos = rondaMayor;

        rlutil::cls();
        dibujarMarco();
        puntosEntreRonda(contRondas,rondaMayor,acuPuntos);

        rondaMayor=0;
    }
    while(acuPuntos<100); /// CONDICION PARA SEGUIR EN PARTIDA

    rlutil::cls();

    mostrarResultadoFinal(nombre, acuPuntos, contRondas);
    puntaje = acuPuntos;
    rlutil::anykey();
    rlutil::cls();
}



