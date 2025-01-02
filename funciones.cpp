#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include "interfaz.h"
#include "rlutil.h"

using namespace std;

void tirarDados(bool prueba, int vDado[])
{
    if(prueba)
    {
        dadosManual(vDado);
        for(int i=0; i<6; i++)
        {
            dibujarDado(vDado, 10*(i + 3), 20, i);
        }
    }
    else
    {
        dadosRandom(vDado);
        for(int i=0; i<6; i++)
        {
            dibujarDado(vDado, 10*(i + 3), 17, i);
        }
    }


}

void dadosManual(int vDado[])
{
    int num;

    rlutil::locate(50, 16);
    cout << "Ingrese los dados:" << endl;

    for (int i = 0; i < 6; i++)
    {
        rlutil::locate(20 + (i * 15), 18);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "Dado " << i + 1 << ": ";
        rlutil::setColor(rlutil::BROWN);
        cin >> num;
        vDado[i] = num;

    }

}

void dadosRandom(int vDado[])
{
    for(int i=0; i<6; i++)
    {
        vDado[i] = rand() % 6 + 1;
    }
}

int puntosLanzamiento(int vDado[])
{
    bool sext = false;
    bool esc = false;
    int acuDados;

    sext = sexteto(vDado);
    esc = escalera(vDado);

    acuDados = sumaDados(vDado);

    if(sext)
    {
        if(vDado[0]==6)
        {
            return 0;
        }
        else
        {
            return vDado[0]*1000;
        }
    }
    else
    {
        if(esc)
        {
            return 100;
        }
        else
        {
            return acuDados;
        }
    }

}

bool sexteto(int vDado[])
{
    int contSexteto = 0;

    for(int i=0; i<5; i++)
    {
        if(vDado[i]==vDado[i+1])
        {
            contSexteto++;
        }
    }

    if(contSexteto==5)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool escalera(int vDado[])
{
    bool vEsc[6];
    int i, x=1, y;
    int contEscalera = 0;

    for(i=0; i<6; i++)
    {
        vEsc[i]=false;
    }

    for(y=0; y<6; y++)
    {
        for(i=0; i<6; i++)
        {
            if(vDado[i]==x)
            {
                vEsc[y]=true;
            }
        }
        x++;
    }

    for(i=0; i<6; i++)
    {
        if(vEsc[i])
        {
            contEscalera++;
        }
    }
    if(contEscalera==6)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int sumaDados(int vDado[])
{
    int acuSumaDados = 0;
    int i;

    for(i=0; i<6; i++)
    {
        acuSumaDados += vDado[i];
    }
    return acuSumaDados;
}

void mostrarResultadoFinal(const string& nombre, int acuPuntos, int contRondas)
{
    rlutil::cls();
    rlutil::setColor(rlutil::GREEN);

    mostrarLineaCentral("Ganaste " + nombre + "!", 5);
    mostrarLineaCentral("Completaste el juego con " + to_string(acuPuntos) + " puntos: ", 7);
    mostrarLineaCentral("Numero de rondas: " + to_string(contRondas), 9);

    rlutil::setColor(rlutil::DARKGREY);
    mostrarLineaCentral("Presione ENTER para salir...", 11);

    rlutil::resetColor();
    rlutil::anykey();
}

void mostrarPuntosRonda(const string& nombre, int contRondas, int lanzamiento, int puntos, int acuPuntos, int rondaMayor)
{
    rlutil::cls();
    rlutil::setColor(rlutil::BROWN);
    dibujarMarco();

    mostrarLineaCentral("Turno de " + nombre, 3);
    mostrarLineaCentral("RONDA: " + to_string(contRondas), 5);
    mostrarLineaCentral("Lanzamiento: " + to_string(lanzamiento), 7);

    rlutil::resetColor();
    rlutil::setColor(rlutil::LIGHTGREEN);
    mostrarLineaCentral("Puntos de Lanzamiento Maximo: " + to_string(rondaMayor), 9);
    mostrarLineaCentral("PUNTAJE TOTAL: " + to_string(acuPuntos), 11);

    rlutil::resetColor();
}

void puntosEntreRonda(int contRondas, int rondaMayor, int acuPuntos)
{
    rlutil::cls();
    dibujarMarco();

    rlutil::setColor(rlutil::BROWN);
    int cols = rlutil::tcols();

    // Mostrar los datos centrados
    rlutil::locate((cols / 2) - 12, 6);
    cout << "PUNTOS DE LA RONDA " << contRondas << ": " <<rondaMayor;

    rlutil::locate((cols / 2) - 12, 8);
    cout << "PUNTAJE TOTAL: " << acuPuntos;

    rlutil::setColor(rlutil::DARKGREY);
    rlutil::locate((cols / 2) - 15, 10);
    cout << "Presiona cualquier tecla para continuar...";

    rlutil::resetColor();
    rlutil::anykey();
}
void mostrarPuntajes(string jugadores[], int tabla[])
{
    cout<<"PUNTUACIONES"<<endl<<endl;

    for (int i = 0; i < 3; i++)
    {
        if (tabla[i] != 0)    /// solo se muestra los jugadores con puntaje
        {
            cout << "Jugador: " << jugadores[i] << " Puntaje: " << tabla[i] << endl;
        }
    }

    rlutil::anykey();
    rlutil::cls();
}

void cargarPuntajes(string nombre, int puntaje, string nombres[], int tablaPuntajes[])
{
    /// Reemplazar puntajes mayores
    int pos = -1;
    int minPuntaje = tablaPuntajes[0];

    for (int i = 1; i < 3; i++)
    {
        if (tablaPuntajes[i] < minPuntaje)
        {
            minPuntaje = tablaPuntajes[i];
        }
    }

    ///compara el ultimo puntaje jugado con el de menor puntaje de la lista
    if (puntaje <= minPuntaje)
    {
        return;
    }

    ///busca lugar en la tabla, si no hay puntos entra en esa pos
    for (int i = 0; i < 3; i++)
    {
        if (tablaPuntajes[i] == 0)
        {
            pos = i;
            break;
        }
    }

    /// se fija cual es el mas chico para reemplazarlo
    if (pos == -1)
    {

        pos = 0;
        for (int i = 1; i < 3; i++)
        {
            if (tablaPuntajes[i] < tablaPuntajes[pos])
            {
                pos = i;
            }
        }
    }

    ///nuevo jugador
    nombres[pos] = nombre;
    tablaPuntajes[pos] = puntaje;


    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {

            if (tablaPuntajes[i] < tablaPuntajes[j])
            {

                int tempPuntaje = tablaPuntajes[i];
                tablaPuntajes[i] = tablaPuntajes[j];
                tablaPuntajes[j] = tempPuntaje;

                string tempNombre = nombres[i];
                nombres[i] = nombres[j];
                nombres[j] = tempNombre;
            }
        }
    }
}

