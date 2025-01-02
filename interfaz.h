#pragma once

void seleccionar(const char* texto, int posX, int posY, bool elegido);

void dibujarDado(int vDado[], int posx, int posy, int i);

void dibujarCuadrado(int posx,int posy);

void dibujarPuntos(int vDado[], int posx, int posy, int i);

void dibujarBordes(int posx, int posy);

void dibujarMarco();

void animacionPresentacion();

void mostrarLineaCentral(const std::string& texto, int fila);

void mostrarIntroduccion();

void mostrarRonda(const std::string& nombre, int contRondas, int lanzamiento, int puntos, int acuPuntos);

void mostrarIntroduccionSimul();
