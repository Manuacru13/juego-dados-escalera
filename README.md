# Juego de Dados Escalera

Este es un juego de dados de consola creado en C++ utilizando Code::Blocks. El juego tiene como objetivo lograr la mayor cantidad de puntos posible lanzando dados
y utilizando una combinación de reglas específicas para obtener el puntaje más alto en las rondas. El juego incluye opciones para un solo jugador o dos jugadores,
y el jugador que consiga al menos 100 puntos en las rondas o logre una escalera (combinación de números consecutivos) en un solo lanzamiento gana.

## Características

- **Juego de un solo jugador o dos jugadores**: Puedes jugar en solitario o desafiar a otro jugador.
- **Reglas de puntuación**:
  - El puntaje por ronda es el valor máximo obtenido en los tres lanzamientos de los dados.
  - Se otorgan puntos extra por obtener combinaciones especiales como una escalera o seis dados con el mismo valor.
- **Interfaz de consola**: El juego se ejecuta completamente en la consola, utilizando la biblioteca `rlutil` para la gestión de la interfaz.
- **Mostrar puntuaciones**: El juego muestra las puntuaciones del jugador y permite ver la puntuación más alta obtenida en la sesión.

## Requisitos

- **Sistema operativo**: Windows, Linux o macOS
- **Compilador**: Code::Blocks o cualquier compilador C++ compatible.
- **Bibliotecas**:
  - `rlutil`: Utilizada para la interacción con la consola, como limpiar la pantalla, cambiar colores, etc.

## Instalación

### Requisitos previos

Antes de ejecutar el juego, asegúrate de tener instalado **Code::Blocks** y la biblioteca `rlutil`.

1. **Instala Code::Blocks**: Descarga e instala Code::Blocks desde [su página oficial](http://www.codeblocks.org/).
2. **Instala rlutil**: Asegúrate de tener la biblioteca `rlutil` configurada correctamente en tu proyecto.

### Clonar el repositorio

```bash
git clone https://github.com/Manuacru13/juego-dados-escalera.git
