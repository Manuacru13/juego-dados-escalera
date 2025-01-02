#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "interfaz.h"
#include "rlutil.h"
#include "funciones.h"



using namespace std;

void seleccionar(const char* texto, int posX, int posY, bool elegido){

    if(elegido){
        rlutil::setBackgroundColor(rlutil::BROWN);
        rlutil::locate(posX - 2, posY);
        cout<< char (175) << " " << " " << endl;
    }else{
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(posX - 2, posY);
        cout<< " " << " " <<endl;
    }

    rlutil::locate(posX, posY);
    cout<< texto <<endl;
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void dibujarDado(int vDado[], int posx, int posy, int i){
    dibujarCuadrado(posx, posy);
    dibujarPuntos(vDado, posx, posy, i);
    dibujarBordes(posx, posy);
}

void dibujarCuadrado(int posx,int posy){ // Dibuja un cuadrado de 7 columnas (de posx a posx+6) y 3 filas (de posy a posy+2)
     rlutil::setColor(rlutil::WHITE);
    for(int x=posx; x<=posx+6; x++){
        for(int y=posy; y<=posy+2; y++){
            rlutil::locate(x,y);
            cout<< (char)219;
        }
    }
}

void dibujarPuntos(int vDado[], int posx, int posy, int i){

    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);

    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);


    i=vDado[i];

        switch(i){
        case 1:
        rlutil::locate(posx+3,posy+1);
        cout<< (char) 254;
        break;

        case 2:
        rlutil::locate(posx+1,posy);
        cout<< (char) 220;
        rlutil::locate(posx+5,posy+2);
        cout<< (char) 223;
        break;

        case 3:
        rlutil::locate(posx+3,posy+1);
        cout<< (char) 254;
        rlutil::locate(posx+1,posy);
        cout<< (char) 220;
        rlutil::locate(posx+5,posy+2);
        cout<< (char) 223;
        break;

        case 4:
        rlutil::locate(posx+1,posy);
        cout<< (char) 220;
        rlutil::locate(posx+5,posy);
        cout<< (char) 220;
         rlutil::locate(posx+1,posy+2);
        cout<< (char) 223;
        rlutil::locate(posx+5,posy+2);
        cout<< (char) 223;
        break;

        case 5:
        rlutil::locate(posx+1,posy);
        cout<< (char) 220;
        rlutil::locate(posx+5,posy);
        cout<< (char) 220;
         rlutil::locate(posx+1,posy+2);
        cout<< (char) 223;
        rlutil::locate(posx+5,posy+2);
        cout<< (char) 223;
        rlutil::locate(posx+3,posy+1);
        cout<< (char) 254;
        break;

        case 6:
        rlutil::locate(posx+1,posy);
        cout<< (char) 220;
        rlutil::locate(posx+3,posy);
        cout<< (char) 220;
        rlutil::locate(posx+5,posy);
        cout<< (char) 220;
         rlutil::locate(posx+1,posy+2);
        cout<< (char) 223;
        rlutil::locate(posx+3,posy+2);
        cout<< (char) 223;
        rlutil::locate(posx+5,posy+2);
        cout<< (char) 223;
        break;
    }
}

void dibujarBordes(int posx, int posy){

    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::BLACK);

    for(int y=0; y<3; y++){
        rlutil::locate(posx+7, y+posy+1);
        cout<< (char)219 <<endl;
    }

    for(int x=0; x<7; x++){
        rlutil::locate(x+posx+1, posy+3);
        cout<< (char)223 <<endl;
    }

    rlutil::locate(posx+7, posy);
    cout<< (char)220 <<endl;
}

void dibujarMarco() {
    int cols = rlutil::tcols();
    int rows = rlutil::trows();
    rlutil::setColor(rlutil::DARKGREY);

    // Esquinas
    rlutil::locate(2, 3);  std::cout << char(218);  // Esquina superior izquierda
    rlutil::locate(cols - 1, 3); std::cout << char(191);  // Esquina superior derecha
    rlutil::locate(2, rows - 2); std::cout << char(192);  // Esquina inferior izquierda
    rlutil::locate(cols - 1, rows - 2); std::cout << char(217);  // Esquina inferior derecha

    // Bordes horizontales
    for (int x = 3; x < cols - 1; x++) {
        rlutil::locate(x, 3); std::cout << char(196);
        rlutil::locate(x, rows - 2); std::cout << char(196);
    }

    // Bordes verticales
    for (int y = 4; y < rows - 2; y++) {
        rlutil::locate(2, y); std::cout << char(179);
        rlutil::locate(cols - 1, y); std::cout << char(179);
    }
    rlutil::resetColor();
}

void animacionPresentacion() {
    rlutil::hidecursor();
    rlutil::setColor(rlutil::BROWN);
    rlutil::locate(04, 05);
    std::cout << "\
                ########  ######   ######     ###    ##       ######## ########     ### \n";
    std::cout << "\
                   ##       ##    ## ##    ##   ## ##   ##       ##       ##     ##   ## ## \n";
    std::cout << "\
                   ##       ##       ##        ##   ##  ##       ##       ##     ##  ##   ## \n";
    std::cout << "\
                   ######    ######  ##       ##     ## ##       ######   ########  ##     ## \n";
    std::cout << "\
                   ##             ## ##       ######### ##       ##       ##   ##   ######### \n";
    std::cout << "\
                   ##       ##    ## ##    ## ##     ## ##       ##       ##    ##  ##     ## \n";
    std::cout << "\
                   ########  ######   ######  ##     ## ######## ######## ##     ## ##     ## \n";
    rlutil::resetColor();
    rlutil::msleep(2000);  // Espera de 2 segundo

}

void mostrarLineaCentral(const string& texto, int fila) {   // Función para mostrar una línea de texto en el centro
    int cols = rlutil::tcols();             // Obtiene el número total de columnas de la consola
    int longitud = texto.length();          // Calcula la longitud del texto.
    int inicio = (cols - longitud) / 2;     // Determina la posición inicial para centrar el texto.
    rlutil::locate(inicio, fila);
    cout << texto;
}

void mostrarIntroduccion() {
    rlutil::cls();
    rlutil::setColor(rlutil::BROWN);

    // Mensaje introductorio
    mostrarLineaCentral("Bienvenido al juego de Dados - 1 Jugador", 12);
    mostrarLineaCentral("El objetivo es obtener 100 puntos en el menor numero de rondas.", 14);
    rlutil::setColor(rlutil::DARKGREY);
    mostrarLineaCentral("Presiona cualquier tecla para comenzar...", 17);

    rlutil::resetColor();
    rlutil::anykey();
    rlutil::cls();
}

void mostrarIntroduccionSimul() {
    rlutil::cls();
    rlutil::setColor(rlutil::BROWN);

    // Mensaje introductorio
    mostrarLineaCentral("Bienvenido al juego de Dados - Simulacion", 12);
    mostrarLineaCentral("El objetivo es obtener 100 puntos en el menor numero de rondas.", 14);
    rlutil::setColor(rlutil::DARKGREY);
    mostrarLineaCentral("Presiona cualquier tecla para comenzar...", 17);

    rlutil::resetColor();
    rlutil::anykey();
    rlutil::cls();
}

