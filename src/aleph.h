/***************************************************************************
 *   aleph.h                                                           *
 *   Prototipos de las funciones utilizadas en fractalis.c                 *
 ***************************************************************************
 *   Copyright (C) 2004 by                                                 *
 *       Miguel Barousse Ordóñez <emiguelbo@gmail.com>                     *
 *       Octavio Narváez Aroche <ocnaar@yahoo.com>                         *
 *                                                                         *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

void intro();
int menu();
int menuFract();
int menuFract_adicional();
int menuMarcoT();
int opciones();
void pantallaTexto(int);
void fractales(SDL_Surface *, int, int);
void fractales2(SDL_Surface *, int);
void sobrepoblacion(SDL_Surface *,float,float);
void bifurcacion(SDL_Surface *,float);
void automata(int);
void DibujaFractal(SDL_Surface *, int, double, double, double, double, double, int);
int mandelbrot_julia(double, double, double, double);
int mandelbrot3_julia(double, double, double, double);
int mandelbrot4_julia(double, double, double, double);
int mandelbrot5_julia(double, double, double, double);
int newton(double, double);
void collage(SDL_Surface *screen,int tipo);
void DibujaIMG(SDL_Surface *, int, int);
void ActIMG(SDL_Surface *, int, int, int, int, int, int);
void printG(SDL_Surface *, TTF_Font *, const char *, SDL_Color, int, int, int);
void DrawPixel(SDL_Surface *, int, int, Uint8, Uint8, Uint8);
void salida();
void inicializacion();
void Slock(SDL_Surface *);
void Sulock(SDL_Surface *);

int resX, resY, paleta_color, pantallaC;
int num_iter = 300;                        //Número de iteraciones en los fractales. Si se aumenta
SDL_Surface *screen, *texto, *fondo;       //este número, los fractales serán de mayor calidad,
TTF_Font *fuente;                          //a costa de mayor tiempo de cálculo. Si se tiene una
SDL_Color blanco = {255,255,255,0};        //computadora poderosa, se puede incrementar
SDL_Color negro = {0,0,0,0};               //considerablemente num_iter.
SDL_Color rojo = {205,12,0,0};
SDL_Color amarillo = {255, 255, 153,0};
