#include <iostream>
#include <cstdlib>
#include "rlutil.h"
#include "funciones.h"
#include "interfaz.h"

using namespace std;

void modoSimulacion(bool prueba, string &nombre, int &puntaje)
{

    int rondaMayor=0, vDado[6];
    int puntos = 0, acuPuntos = 0;
    int contRondas = 0;
    int puntosRonda=0;

    mostrarIntroduccionSimul();

    rlutil::locate(45,13);
    cout<<"Ingrese su nombre: ";
    cin>>nombre;

    do
    {
        contRondas++;
        for(int i=0; i<3; i++)
        {
            // Mostrar informacion de la ronda y puntos
            mostrarPuntosRonda(nombre, contRondas, i + 1, puntos, acuPuntos, rondaMayor);
            cout<<endl;
            rlutil::locate(42,14);
            cout<<"Presione una tecla para ingresar dados.."<<endl;
            rlutil::anykey();

            tirarDados(prueba, vDado);

            puntos = puntosLanzamiento(vDado);

            rlutil::setColor(rlutil::LIGHTGREEN);
            rlutil::locate(47, 24);
            cout<<"Puntos del lanzamiento "<<i+1<<" :" <<puntos<<endl; ///Puntos del lanzamiento

            rlutil::anykey();

            rlutil::cls();

            if(puntos == 100 || puntos == 0)
            {
                if(puntos == 100)
                {
                    acuPuntos = 100;
                    rondaMayor = 0;
                }
                else
                {
                    acuPuntos = 0;
                    rondaMayor = 0;
                }

                i=3;        /// Corta la ronda cuando sale "cero o sexteto de 6" y "cien o ESCALERA"
            }
            else
            {
                if(i==0)
                {
                    rondaMayor = puntos;
                }
                else
                {
                    if(puntos > rondaMayor)
                    {
                         puntosRonda = puntos;
                    }
                }   /// identificar la mayor de puntos
            }

        }   /// Terminan los 3 tiros de la ronda

        acuPuntos += rondaMayor;

        rlutil::cls();
        dibujarMarco();
        puntosEntreRonda(contRondas,rondaMayor,acuPuntos);

    }
    while(acuPuntos<100); /// CONDICION PARA SEGUIR EN PARTIDA

    rlutil::cls();

    mostrarResultadoFinal(nombre, acuPuntos, contRondas);
    puntaje = acuPuntos;
    rlutil::anykey();
    rlutil::cls();
}
