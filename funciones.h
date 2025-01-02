#pragma once
using namespace std;

int lanzarDados();

int sumaDados(int vDado[]);

bool escalera(int vDado[]);

bool sexteto(int vDado[]);

void tirarDados(bool prueba, int vDado[]);

void dadosManual(int vDado[]);

void dadosRandom(int vDado[]);

int puntosLanzamiento(int vDado[]);

void mostrarPuntosRonda(const std::string& nombre, int contRondas, int lanzamiento, int puntos, int acuPuntos, int rondaMayor);

void puntosEntreRonda(int contRondas, int rondaMayor, int acuPuntos);

void mostrarResultadoFinal(const std::string& nombre, int acuPuntos, int contRondas);

void mostrarPuntajes(string jugadores[],int tabla[]);

void cargarPuntajes(string nombre, int puntaje, string nombres[], int tablaPuntajes[]);

