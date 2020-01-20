/***************************************************************************
 *   acciones.c  Diversas acciones repetitivas.                            *
 *   Copyright (C) 2004 by                                                 *
 *       Miguel Barousse Ordóñez <miguelbo@gmail.com>                      *
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

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
extern SDL_Surface *screen, *texto, *fondo;
extern TTF_Font *fuente;
extern int paleta_color, pantallaC;
extern SDL_Color blanco, negro, rojo, amarillo;

//Textos de la referencia rapida
void entradas_principal(int resX, int resY, int opcion, SDL_Surface *screen)
{
  int x, y;

  /*Slock(screen);
  for(y = 193; y<=456; y++)
    for(x = 200; x<=411; x++)
      DrawPixel(screen, x, y, 197, 129, 49);
  Sulock(screen);*/
  ActIMG(fondo, 200, 193, 241, 263, 200, 193);

  fuente=TTF_OpenFont("fuentes/vera.ttf", 16);
  switch(opcion)
  {
    case 0:
      printG(texto, fuente, "Referencia Rápida:", blanco,'b', 460, resY/2-98);
      printG(texto, fuente, "Elija una opción de", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "la izquierda, si tiene", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "alguna duda sobre el", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "programa, seleccione", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "la opción Ayuda.", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      fuente=TTF_OpenFont("fuentes/vera.ttf", 24);
      printG(texto, fuente, "Generar Fractales", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Marco Teórico", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Créditos", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "Opciones", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "Ayuda", blanco,'n',202, resY/2 + 80);
      printG(texto, fuente, "Salir", blanco,'n',202, resY/2 + 128);

      break;
    case 1:
      printG(texto, fuente, "Referencia Rápida:", blanco,'b', 460, resY/2-98);
      printG(texto, fuente, "Permite escoger entre", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "diferentes tipos de", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "fractales para verlos,", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "interactuar con ellos,", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "y explorarlos.", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      fuente=TTF_OpenFont("fuentes/vera.ttf", 24);
      printG(texto, fuente, "Generar Fractales", rojo,'n',202, resY/2 - 112);
      printG(texto, fuente, "Marco Teórico", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Créditos", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "Opciones", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "Ayuda", blanco,'n',202, resY/2 + 80);
      printG(texto, fuente, "Salir", blanco,'n',202, resY/2 + 128);
      break;
    case 2:
      printG(texto, fuente, "Referencia Rápida:", blanco,'b', 460, resY/2-98);
      printG(texto, fuente, "Muestra una reseña", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "histórica sobre los", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "fractales, qué son,", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "cómo se generan, y", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "qué hay detrás de", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      printG(texto, fuente, "ellos.", blanco,'n', 460, resY/2-98+6*TTF_FontLineSkip(fuente)+12);
      fuente=TTF_OpenFont("fuentes/vera.ttf", 24);
      printG(texto, fuente, "Marco Teórico", rojo,'n',202, resY/2 - 64);
      printG(texto, fuente, "Generar Fractales", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Créditos", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "Opciones", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "Ayuda", blanco,'n',202, resY/2 + 80);
      printG(texto, fuente, "Salir", blanco,'n',202, resY/2 + 128);
      break;
    case 3:
      printG(texto, fuente, "Referencia Rápida:", blanco,'b', 460, resY/2-98);
      printG(texto, fuente, "Muestra información", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "sobre los autores y", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "la licencia de uso", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "de este software.", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      fuente=TTF_OpenFont("fuentes/vera.ttf", 24);
      printG(texto, fuente, "Créditos", rojo,'n',202, resY/2 - 16);
      printG(texto, fuente, "Generar Fractales", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Marco Teórico", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Opciones", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "Ayuda", blanco,'n',202, resY/2 + 80);
      printG(texto, fuente, "Salir", blanco,'n',202, resY/2 + 128);
      break;
    case 4:
      printG(texto, fuente, "Referencia Rápida:", blanco,'b', 460, resY/2-98);
      printG(texto, fuente, "Permite seleccionar", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "diferentes paletas", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "de colores para la", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "generación de frac-", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "tales de Mandelbrot", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      printG(texto, fuente, "y Julia.", blanco,'n', 460, resY/2-98+6*TTF_FontLineSkip(fuente)+12);
      fuente=TTF_OpenFont("fuentes/vera.ttf", 24);
      printG(texto, fuente, "Opciones", rojo,'n',202, resY/2 + 32);
      printG(texto, fuente, "Generar Fractales", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Marco Teórico", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Créditos", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "Ayuda", blanco,'n',202, resY/2 + 80);
      printG(texto, fuente, "Salir", blanco,'n',202, resY/2 + 128);
      break;
    case 5:
      printG(texto, fuente, "Referencia Rápida:", blanco,'b', 460, resY/2-98);
      printG(texto, fuente, "Muestra ayuda sobre", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "la utilización de", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "este programa, y la", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "navegación por los", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "fractales.", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      fuente=TTF_OpenFont("fuentes/vera.ttf", 24);
      printG(texto, fuente, "Ayuda", rojo,'n',202, resY/2 + 80);
      printG(texto, fuente, "Generar Fractales", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Marco Teórico", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Créditos", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "Opciones", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "Salir", blanco,'n',202, resY/2 + 128);
      break;
    case 6:
      printG(texto, fuente, "Referencia Rápida:", blanco,'b', 460, resY/2-98);
      printG(texto, fuente, "Termina el programa.", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "Si desea regresar a", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "cualquier pantalla", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "anterior, puede", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "hacerlo con ESC.", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      fuente=TTF_OpenFont("fuentes/vera.ttf", 24);
      printG(texto, fuente, "Salir", rojo,'n',202, resY/2 + 128);
      printG(texto, fuente, "Generar Fractales", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Marco Teórico", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Créditos", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "Opciones", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "Ayuda", blanco,'n',202, resY/2 + 80);
      break;

  }
}

void icon_menu_princ(SDL_Surface *screen, int resX, int resY)
{
  int x, y;
  SDL_Surface *ico_fractal, *ico_teoria, *ico_opciones, *ico_creditos, *ico_ayuda, *ico_salir;
  Slock(screen);

  /*for(y = 186; y<=462; y++)
    for(x = 148; x<=185; x++)
      DrawPixel(screen, x, y, 238, 238, 238);//197, 129, 49);
  Sulock(screen);*/

  ico_fractal = IMG_Load("imagenes/iconos/fractal.png");
  ico_teoria = IMG_Load("imagenes/iconos/teoria.png");
  ico_creditos = IMG_Load("imagenes/iconos/creditos.png");
  ico_opciones = IMG_Load("imagenes/iconos/opciones.png");
  ico_ayuda = IMG_Load("imagenes/iconos/ayuda.png");
  ico_salir = IMG_Load("imagenes/iconos/salir.png");
  
  DibujaIMG(ico_fractal, 150, resY/2 - 112);
  DibujaIMG(ico_teoria, 150, resY/2 - 64);
  DibujaIMG(ico_creditos, 150, resY/2 - 16);
  DibujaIMG(ico_opciones, 150, resY/2 + 32);
  DibujaIMG(ico_ayuda, 150, resY/2 + 80);
  DibujaIMG(ico_salir, 150, resY/2 + 128);

  SDL_FreeSurface(ico_fractal);
  SDL_FreeSurface(ico_teoria);
  SDL_FreeSurface(ico_creditos);
  SDL_FreeSurface(ico_opciones);
  SDL_FreeSurface(ico_ayuda);
  SDL_FreeSurface(ico_salir);
}


void entradas_fractal(int resX, int resY, int opcion, SDL_Surface *screen)
{
  int x, y;

  if (opcion != 13)
  {
    /*Slock(screen);
    for(y = 185; y<=552; y++)
      for(x = 195; x<=450; x++)
        DrawPixel(screen, x, y, 197, 129, 49);
    Sulock(screen);*/
    ActIMG(fondo, 195, 185, 255, 410, 195, 185);
  }

  fuente=TTF_OpenFont("fuentes/vera.ttf", 16);  
  switch(opcion)
  {
    case 0:
      printG(texto, fuente, "Si desea información", blanco,'n', 460, resY/2-98);
      printG(texto, fuente, "sobre algún fractal", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "presione su icono \"?\"", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "Para obtener ayuda", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "sobre la navegación", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "por los fractales,", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      printG(texto, fuente, "seleccione la opción", blanco,'n', 460, resY/2-98+6*TTF_FontLineSkip(fuente)+12);
      printG(texto, fuente, "ayuda en el menú", blanco,'n', 460, resY/2-98+7*TTF_FontLineSkip(fuente)+14);
      printG(texto, fuente, "principal.", blanco,'n', 460, resY/2-98+8*TTF_FontLineSkip(fuente)+16);

      fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
      printG(texto, fuente, "Conjunto de Mandelbrot y", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "conjuntos de Julia.", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Fractales formados", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "por el método de", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "Barnsley.", blanco,'n',202, resY/2 + 80);
      printG(texto, fuente, "Sobrepoblaciones y", blanco,'n',202, resY/2 + 128);
      printG(texto, fuente, "Bifurcaciones.", blanco,'n',202, resY/2 + 176);
      printG(texto, fuente, "Autómata Celular.", blanco,'n',202, resY/2 + 224);
      printG(texto, fuente, "<<Más Fractales>>", amarillo,'n',202, resY/2 + 272);

      break;
    case 1:
      printG(texto, fuente, "Puede ciclar entre", blanco,'n', 460, resY/2-98);
      printG(texto, fuente, "el fractal de Mandel-", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "brot y Julia con la", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "tecla \"->\". El punto", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "que elija en el fractal", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "de Mandelbrot se", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      printG(texto, fuente, "utilizará para generar", blanco,'n', 460, resY/2-98+6*TTF_FontLineSkip(fuente)+12);
      printG(texto, fuente, "el de Julia.", blanco,'n', 460, resY/2-98+7*TTF_FontLineSkip(fuente)+14);

      fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
      printG(texto, fuente, "Conjunto de Mandelbrot y", rojo,'n',202, resY/2 - 112);
      printG(texto, fuente, "conjuntos de Julia.", rojo,'n',202, resY/2 - 64);
      printG(texto, fuente, "Fractales formados", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "por el método de", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "Barnsley.", blanco,'n',202, resY/2 + 80);
      printG(texto, fuente, "Sobrepoblaciones y", blanco,'n',202, resY/2 + 128);
      printG(texto, fuente, "Bifurcaciones.", blanco,'n',202, resY/2 + 176);
      printG(texto, fuente, "Autómata Celular.", blanco,'n',202, resY/2 + 224);
      printG(texto, fuente, "<<Más Fractales>>", amarillo,'n',202, resY/2 + 272);
      break;
    case 2:
      printG(texto, fuente, "Puede cambiar de", blanco,'n', 460, resY/2-98);
      printG(texto, fuente, "fractal con la tecla", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "\"->\", se inicia con el", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "triángulo de Sierpinski,", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "se sigue con un", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "helecho fractal, y", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      printG(texto, fuente, "finalmente se genera", blanco,'n', 460, resY/2-98+6*TTF_FontLineSkip(fuente)+12);
      printG(texto, fuente, "un arbusto.", blanco,'n', 460, resY/2-98+7*TTF_FontLineSkip(fuente)+14);

      fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
      printG(texto, fuente, "Conjunto de Mandelbrot y", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "conjuntos de Julia.", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Fractales formados", rojo,'n',202, resY/2 - 16);
      printG(texto, fuente, "por el método de", rojo,'n',202, resY/2 + 32);
      printG(texto, fuente, "Barnsley.", rojo,'n',202, resY/2 + 80);
      printG(texto, fuente, "Sobrepoblaciones y", blanco,'n',202, resY/2 + 128);
      printG(texto, fuente, "Bifurcaciones.", blanco,'n',202, resY/2 + 176);
      printG(texto, fuente, "Autómata Celular.", blanco,'n',202, resY/2 + 224);
      printG(texto, fuente, "<<Más Fractales>>", amarillo,'n',202, resY/2 + 272);
      break;
    case 3:
      printG(texto, fuente, "Puede cambiar al", blanco,'n', 460, resY/2-98);
      printG(texto, fuente, "siguiente fractal", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "con la tecla \"n\".", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "Con las teclas de", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "flecha arriba y abajo", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "varía la población", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      printG(texto, fuente, "inicial, y con izq. y", blanco,'n', 460, resY/2-98+6*TTF_FontLineSkip(fuente)+12);
      printG(texto, fuente, "derecha varía el pará-", blanco,'n', 460, resY/2-98+7*TTF_FontLineSkip(fuente)+14);
      printG(texto, fuente, "metro de crecimiento.", blanco,'n', 460, resY/2-98+8*TTF_FontLineSkip(fuente)+14);

      fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
      printG(texto, fuente, "Conjunto de Mandelbrot y", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "conjuntos de Julia.", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Fractales formados", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "por el método de", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "Barnsley.", blanco,'n',202, resY/2 + 80);
      printG(texto, fuente, "Sobrepoblaciones y", rojo,'n',202, resY/2 + 128);
      printG(texto, fuente, "Bifurcaciones.", rojo,'n',202, resY/2 + 176);
      printG(texto, fuente, "Autómata Celular.", blanco,'n',202, resY/2 + 224);
      printG(texto, fuente, "<<Más Fractales>>", amarillo,'n',202, resY/2 + 272);
      break;
    case 4:
      printG(texto, fuente, "En el autómata celular", blanco,'n', 460, resY/2-98);
      printG(texto, fuente, "se pueden cambiar las", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "condiciones iniciales", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "presionando la tecla", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "flecha derecha del", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "teclado.", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);

      fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
      printG(texto, fuente, "Conjunto de Mandelbrot y", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "conjuntos de Julia.", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Fractales formados", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "por el método de", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "Barnsley.", blanco,'n',202, resY/2 + 80);
      printG(texto, fuente, "Sobrepoblaciones y", blanco,'n',202, resY/2 + 128);
      printG(texto, fuente, "Bifurcaciones.", blanco,'n',202, resY/2 + 176);
      printG(texto, fuente, "Autómata Celular.", rojo,'n',202, resY/2 + 224);
      printG(texto, fuente, "<<Más Fractales>>", amarillo,'n',202, resY/2 + 272);
      break;
    case 14:
      printG(texto, fuente, "Fractales adicionales:", blanco,'n', 460, resY/2-98);
      printG(texto, fuente, "", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "  - Mandelbrot^3", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "  - Mandelbrot^4", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "  - Mandelbrot^5", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "  - Newton-Raphson", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);

      fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
      printG(texto, fuente, "Conjunto de Mandelbrot y", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "conjuntos de Julia.", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Fractales formados", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "por el método de", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "Barnsley.", blanco,'n',202, resY/2 + 80);
      printG(texto, fuente, "Sobrepoblaciones y", blanco,'n',202, resY/2 + 128);
      printG(texto, fuente, "Bifurcaciones.", blanco,'n',202, resY/2 + 176);
      printG(texto, fuente, "Autómata Celular.", blanco,'n',202, resY/2 + 224);
      printG(texto, fuente, "<<Más Fractales>>", rojo,'n',202, resY/2 + 272);
      break;
    case 13:
      fuente=TTF_OpenFont("fuentes/vera.ttf", 16);
      printG(texto, fuente, "Regresar al menu", blanco,'b', 460, resY/2-98);
      printG(texto, fuente, "principal.", blanco,'b', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      break;

  }
}

void icon_fractal(SDL_Surface *screen, int resX, int resY)
{
  int x, y;
  SDL_Surface *ico_ayuda, *ico_atras;
  Slock(screen);

  /*for(y = 186; y<=558; y++)
    for(x = 148; x<=185; x++)
      DrawPixel(screen, x, y, 238, 238, 238);//197, 129, 49);
  Sulock(screen);*/

  ico_ayuda = IMG_Load("imagenes/iconos/ayuda.png");
  ico_atras = IMG_Load("imagenes/iconos/atras.png");
  
  DibujaIMG(ico_ayuda, 150, 187);
  DibujaIMG(ico_ayuda, 150, 283);
  DibujaIMG(ico_ayuda, 150, 427);
  DibujaIMG(ico_ayuda, 150, 523);
  DibujaIMG(ico_atras, 738, resY/2 + 224);

  SDL_FreeSurface(ico_ayuda);
  SDL_FreeSurface(ico_atras);
}

void entradas_fractal_adicional(int resX, int resY, int opcion, SDL_Surface *screen)
{
  int x, y;

  if (opcion != 13)
  {
    /*Slock(screen);
    for(y = 185; y<=552; y++)
      for(x = 195; x<=450; x++)
        DrawPixel(screen, x, y, 197, 129, 49);
    Sulock(screen);*/
    ActIMG(fondo, 195, 185, 255, 410, 195, 185);
  }

  fuente=TTF_OpenFont("fuentes/vera.ttf", 16);  
  switch(opcion)
  {
    case 0:
      printG(texto, fuente, "Si desea información", blanco,'n', 460, resY/2-98);
      printG(texto, fuente, "sobre algún fractal", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "presione su icono \"?\"", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "Para obtener ayuda", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "sobre la navegación", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "por los fractales,", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      printG(texto, fuente, "seleccione la opción", blanco,'n', 460, resY/2-98+6*TTF_FontLineSkip(fuente)+12);
      printG(texto, fuente, "ayuda en el menú", blanco,'n', 460, resY/2-98+7*TTF_FontLineSkip(fuente)+14);
      printG(texto, fuente, "principal.", blanco,'n', 460, resY/2-98+8*TTF_FontLineSkip(fuente)+16);

      fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
      printG(texto, fuente, "Mandelbrot^3", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Mandelbrot^4", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Mandelbrot^5", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "Newton-Raphson", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "<<Más Fractales>>", amarillo,'n',202, resY/2 + 272);

      break;
    case 21:
      printG(texto, fuente, "Puede ciclar entre", blanco,'n', 460, resY/2-98);
      printG(texto, fuente, "el fractal de Mandel-", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "brot^3 y Julia con la", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "tecla \"->\". El punto", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "que elija en el fractal", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "de Mandelbrot^3 se", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      printG(texto, fuente, "utilizará para generar", blanco,'n', 460, resY/2-98+6*TTF_FontLineSkip(fuente)+12);
      printG(texto, fuente, "el de Julia.", blanco,'n', 460, resY/2-98+7*TTF_FontLineSkip(fuente)+14);

      fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
      printG(texto, fuente, "Mandelbrot^3", rojo,'n',202, resY/2 - 112);
      printG(texto, fuente, "Mandelbrot^4", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Mandelbrot^5", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "Newton-Raphson", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "<<Más Fractales>>", amarillo,'n',202, resY/2 + 272);
      break;
    case 22:
      printG(texto, fuente, "Puede ciclar entre", blanco,'n', 460, resY/2-98);
      printG(texto, fuente, "el fractal de Mandel-", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "brot^4 y Julia con la", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "tecla \"->\". El punto", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "que elija en el fractal", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "de Mandelbrot^4 se", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      printG(texto, fuente, "utilizará para generar", blanco,'n', 460, resY/2-98+6*TTF_FontLineSkip(fuente)+12);
      printG(texto, fuente, "el de Julia.", blanco,'n', 460, resY/2-98+7*TTF_FontLineSkip(fuente)+14);

      fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
      printG(texto, fuente, "Mandelbrot^3", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Mandelbrot^4", rojo,'n',202, resY/2 - 64);
      printG(texto, fuente, "Mandelbrot^5", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "Newton-Raphson", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "<<Más Fractales>>", amarillo,'n',202, resY/2 + 272);
      break;
    case 23:
      printG(texto, fuente, "Puede ciclar entre", blanco,'n', 460, resY/2-98);
      printG(texto, fuente, "el fractal de Mandel-", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "brot^5 y Julia con la", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "tecla \"->\". El punto", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "que elija en el fractal", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "de Mandelbrot^5 se", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      printG(texto, fuente, "utilizará para generar", blanco,'n', 460, resY/2-98+6*TTF_FontLineSkip(fuente)+12);
      printG(texto, fuente, "el de Julia.", blanco,'n', 460, resY/2-98+7*TTF_FontLineSkip(fuente)+14);

      fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
      printG(texto, fuente, "Mandelbrot^3", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Mandelbrot^4", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Mandelbrot^5", rojo,'n',202, resY/2 - 16);
      printG(texto, fuente, "Newton-Raphson", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "<<Más Fractales>>", amarillo,'n',202, resY/2 + 272);
      break;
    case 24:
      printG(texto, fuente, "Puede navegar en el", blanco,'n', 460, resY/2-98);
      printG(texto, fuente, "fractal de Newton-", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "Raphson como en", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "cualquier otro fractal", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "(diferentes escalas,", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "desplazamientos).", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);

      fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
      printG(texto, fuente, "Mandelbrot^3", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Mandelbrot^4", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Mandelbrot^5", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "Newton-Raphson", rojo,'n',202, resY/2 + 32);
      printG(texto, fuente, "<<Más Fractales>>", amarillo,'n',202, resY/2 + 272);
      break;
    case 15:
      printG(texto, fuente, "Fractales adicionales:", blanco,'n', 460, resY/2-98);
      printG(texto, fuente, "", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      printG(texto, fuente, "  - Mandelbrot", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
      printG(texto, fuente, "  - Formados por el", blanco,'n', 460, resY/2-98+3*TTF_FontLineSkip(fuente)+6);
      printG(texto, fuente, "    método de Barnsley", blanco,'n', 460, resY/2-98+4*TTF_FontLineSkip(fuente)+8);
      printG(texto, fuente, "  - Sobrepoblaciones y", blanco,'n', 460, resY/2-98+5*TTF_FontLineSkip(fuente)+10);
      printG(texto, fuente, "    bifurcaciones.", blanco,'n', 460, resY/2-98+6*TTF_FontLineSkip(fuente)+12);
      printG(texto, fuente, "  - Autómata celular.", blanco,'n', 460, resY/2-98+7*TTF_FontLineSkip(fuente)+14);


      fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
      printG(texto, fuente, "Mandelbrot^3", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Mandelbrot^4", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "Mandelbrot^5", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "Newton-Raphson", blanco,'n',202, resY/2 + 32);
      printG(texto, fuente, "<<Más Fractales>>", rojo,'n',202, resY/2 + 272);
      break;
    case 13:
      fuente=TTF_OpenFont("fuentes/vera.ttf", 16);
      printG(texto, fuente, "Regresar al menu", blanco,'b', 460, resY/2-98);
      printG(texto, fuente, "principal.", blanco,'b', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      break;

  }
}

void icon_fractal_adicional(SDL_Surface *screen, int resX, int resY)
{
  int x, y;
  SDL_Surface *ico_ayuda, *ico_atras;
  Slock(screen);

  /*for(y = 186; y<=558; y++)
    for(x = 148; x<=185; x++)
      DrawPixel(screen, x, y, 238, 238, 238);//197, 129, 49);
  Sulock(screen);*/

  ico_ayuda = IMG_Load("imagenes/iconos/ayuda.png");
  ico_atras = IMG_Load("imagenes/iconos/atras.png");
  
  DibujaIMG(ico_ayuda, 150, 185);
  DibujaIMG(ico_ayuda, 150, 233);
  DibujaIMG(ico_ayuda, 150, 281);
  DibujaIMG(ico_ayuda, 150, 329);
  DibujaIMG(ico_atras, 738, resY/2 + 224);

  SDL_FreeSurface(ico_ayuda);
  SDL_FreeSurface(ico_atras);
}

void entradas_marcoT(int resX, int resY, int opcion, SDL_Surface *screen)
{
  int x, y;

  if (opcion != 4)
  {
    /*Slock(screen);
    for(y = 193; y<=552; y++)
      for(x = 200; x<=450; x++)
        DrawPixel(screen, x, y, 197, 129, 49);
    Sulock(screen);*/
    ActIMG(fondo, 200, 190, 250, 359, 200, 193);

    fuente=TTF_OpenFont("fuentes/vera.ttf", 16);
    printG(texto, fuente, "Selecciona del menu", blanco,'n', 460, resY/2-98);
    printG(texto, fuente, "de la izquierda el", blanco,'n', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
    printG(texto, fuente, "tema que desees ver.", blanco,'n', 460, resY/2-98+2*TTF_FontLineSkip(fuente)+4);
  }
    
  fuente=TTF_OpenFont("fuentes/vera.ttf", 20);
  switch(opcion)
  {
    case 0:
      printG(texto, fuente, "¿Qué es un fractal?", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Un mundo de fractales", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "¿Qué hay detrás de", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "los fractales?", blanco,'n',202, resY/2 + 32);
      break;
    case 1:
      printG(texto, fuente, "¿Qué es un fractal?", rojo,'n',202, resY/2 - 112);
      printG(texto, fuente, "Un mundo de fractales", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "¿Qué hay detrás de", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "los fractales?", blanco,'n',202, resY/2 + 32);
      break;
    case 2:
      printG(texto, fuente, "¿Qué es un fractal?", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Un mundo de fractales", rojo,'n',202, resY/2 - 64);
      printG(texto, fuente, "¿Qué hay detrás de", blanco,'n',202, resY/2 - 16);
      printG(texto, fuente, "los fractales?", blanco,'n',202, resY/2 + 32);
      break;
    case 3:
      printG(texto, fuente, "¿Qué es un fractal?", blanco,'n',202, resY/2 - 112);
      printG(texto, fuente, "Un mundo de fractales", blanco,'n',202, resY/2 - 64);
      printG(texto, fuente, "¿Qué hay detrás de", rojo,'n',202, resY/2 - 16);
      printG(texto, fuente, "los fractales?", rojo,'n',202, resY/2 + 32);
      break;
    case 4:
      fuente=TTF_OpenFont("fuentes/vera.ttf", 16);
      printG(texto, fuente, "Regresar al menu", blanco,'b', 460, resY/2-98);
      printG(texto, fuente, "principal.", blanco,'b', 460, resY/2-98+TTF_FontLineSkip(fuente)+2);
      break;
  }
}

void icon_marcoT(SDL_Surface *screen, int resX, int resY)
{
  int x, y;
  SDL_Surface *ico_historia, *ico_quees, *ico_detras, *ico_atras;
  Slock(screen);

  /*for(y = 186; y<=366; y++)
    for(x = 148; x<=185; x++)
      DrawPixel(screen, x, y, 238, 238, 238);//197, 129, 49);
  Sulock(screen);*/

  ico_historia = IMG_Load("imagenes/iconos/historia.png");
  ico_quees = IMG_Load("imagenes/iconos/quees.png");
  ico_detras = IMG_Load("imagenes/iconos/detras.png");
  ico_atras = IMG_Load("imagenes/iconos/atras.png");
  
  DibujaIMG(ico_historia, 150, resY/2 - 112);
  DibujaIMG(ico_quees, 150, resY/2 - 64);
  DibujaIMG(ico_detras, 150, resY/2 - 16);
  DibujaIMG(ico_atras, 738, resY/2 + 224);

  SDL_FreeSurface(ico_historia);
  SDL_FreeSurface(ico_quees);
  SDL_FreeSurface(ico_detras);
  SDL_FreeSurface(ico_atras);
}

int entradas_opciones()
{
  int desp;

  fuente=TTF_OpenFont("fuentes/vera.ttf", 24);
  desp = TTF_FontLineSkip(fuente);
  printG(texto, fuente, "Paleta de Colores", blanco,'b',130, 188);
  printG(texto, fuente, "Modo de Vídeo", blanco,'b',130, 188+9*desp);
  
  fuente=TTF_OpenFont("fuentes/vera.ttf", 14);
  printG(texto, fuente, "Seleccione la combinación de colores que se utilizará para generar los fractales.", blanco,'n',130, 188+desp);
  
  fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
  printG(texto, fuente, "Por Defecto:", blanco,'n',188, 188 + 3*desp);
  printG(texto, fuente, "Otoño:", blanco,'n',188, 188 + 4*desp);
  printG(texto, fuente, "Púrpura Profundo:", blanco,'n',188, 188 + 5*desp);
  printG(texto, fuente, "Atardecer Eléctrico:", blanco,'n',188, 188 + 6*desp);
  printG(texto, fuente, "Verduzco:", blanco,'n',188, 188 + 7*desp);
  printG(texto, fuente, "Pantalla Completa/Modo de Ventana", blanco,'n',188, 188 + 11*desp);
  
  return desp;
}

void icon_opciones(int desp)
{
  int x, y;
  SDL_Surface *check, *uncheck;

  uncheck = IMG_Load("imagenes/opciones/box.png");
  check = IMG_Load("imagenes/opciones/check_box.png");

  ActIMG(fondo, 170, 272, 18, 127, 170, 272);
  DibujaIMG(uncheck, 170, 188 + 3*desp);
  DibujaIMG(uncheck, 170, 188 + 4*desp);
  DibujaIMG(uncheck, 170, 188 + 5*desp);
  DibujaIMG(uncheck, 170, 188 + 6*desp);
  DibujaIMG(uncheck, 170, 188 + 7*desp);
  DibujaIMG(uncheck, 170, 188 + 11*desp);
  
  switch (paleta_color)
  {
    case 0:
      DibujaIMG(check, 170, 188 + 3*desp);
      break;
    case 1:
      DibujaIMG(check, 170, 188 + 4*desp);
      break;
    case 2:
      DibujaIMG(check, 170, 188 + 5*desp);
      break;
    case 3:
      DibujaIMG(check, 170, 188 + 6*desp);
      break;
    case 4:
      DibujaIMG(check, 170, 188 + 7*desp);
      break;
  }
  if (pantallaC == 1) DibujaIMG(check, 170, 188 + 11*desp);
  
  SDL_FreeSurface(check);
  SDL_FreeSurface(uncheck);
}

void escribe_titulo(int opcion)
{
  SDL_Surface *icono;
  
  fuente=TTF_OpenFont("fuentes/vera.ttf", 24);
  switch (opcion)
  {
    case 1:
      printG(texto, fuente, "¿Qué es un fractal?", blanco,'b', 75, 166);
      icono = IMG_Load("imagenes/iconos/historia.png");
      break;
    case 2:
      printG(texto, fuente, "En un mundo de fractales", blanco,'b', 75, 166);
      icono = IMG_Load("imagenes/iconos/quees.png");
      break;
    case 3:
      printG(texto, fuente, "¿Qué hay detrás de los fractales?", blanco,'b', 75, 166);
      icono = IMG_Load("imagenes/iconos/detras.png");
      break;
    case 4:
      printG(texto, fuente, "Créditos. Versión 1.1 (Junio de 2005)", blanco,'b', 75, 166);
      icono = IMG_Load("imagenes/iconos/creditos.png");
      break;
    case 5:
      printG(texto, fuente, "Ayuda", blanco,'b', 75, 166);
      icono = IMG_Load("imagenes/iconos/ayuda.png");
      break;
    case 6:
      printG(texto, fuente, "Conjunto de Mandelbrot y Julia", blanco,'b', 75, 166);
      icono = IMG_Load("imagenes/iconos/ayuda.png");
      break;
    case 7:
      printG(texto, fuente, "Fractales generados por el Método de Barnsley", blanco,'b', 75, 166);
      icono = IMG_Load("imagenes/iconos/ayuda.png");
      break;
    case 8:
      printG(texto, fuente, "Crecimiento de la población", blanco,'b', 75, 166);
      icono = IMG_Load("imagenes/iconos/ayuda.png");
      break;
    case 9:
      printG(texto, fuente, "Autómata Celular", blanco,'b', 75, 166);
      icono = IMG_Load("imagenes/iconos/ayuda.png");
      break;
    case 10:
      printG(texto, fuente, "Conjunto de Mandelbrot^n", blanco,'b', 75, 166);
      icono = IMG_Load("imagenes/iconos/ayuda.png");
      break;
    case 11:
      printG(texto, fuente, "Fractal de Newton-Raphson", blanco,'b', 75, 166);
      icono = IMG_Load("imagenes/iconos/ayuda.png");
      break;

  }
  DibujaIMG(icono, 40, 166);

  SDL_FreeSurface(icono);
}

int inserta_texto(int opcion, int posicion, SDL_Surface *screen)
{
  int n=-posicion + 1, maximo, x, y;
  SDL_Surface *textbox;
  
  //Dibuja recuadro de texto
  /*Slock(screen);
  for (x = 40; x<=744; x++)
    for (y=200; y<=560; y++)
      DrawPixel(screen, x, y, 238, 238, 238);
  Sulock(screen);*/
  
  textbox = IMG_Load("imagenes/menu/textbox.png");
  DibujaIMG(textbox, 40, 200);
  SDL_FreeSurface(textbox);
  
  fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
  switch(opcion)
  {
    case 1:    //Que son los fractales
      maximo = 36;
      switch(posicion) {
        case 1: printG(texto, fuente, "Es  claro  que la  geometría  de  las  montañas,  nubes, ríos, cascadas,", blanco,'n',45, 205+n*TTF_FontLineSkip(fuente)); if(posicion+16==1) break;
        case 2: printG(texto, fuente, "costas,  árboles,  helechos, vasos sanguíneos y demás objetos natura-", blanco,'n',45, 205+(n+1)*TTF_FontLineSkip(fuente)); if(posicion+16==2) break;
        case 3: printG(texto, fuente, "les, exhibe en apariencia una mayor complejidad que la de los cubos,", blanco,'n',45, 205+(n+2)*TTF_FontLineSkip(fuente)); if(posicion+16==3) break;
        case 4: printG(texto, fuente, "esferas  o  conos;  sin  embargo,  también  es fácil apreciar en ellos la", blanco,'n',45, 205+(n+3)*TTF_FontLineSkip(fuente)); if(posicion+16==4) break;
        case 5: printG(texto, fuente, "existencia  de  la  curiosa  y  para  algunos  perturbante propiedad de", blanco,'n',45, 205+(n+4)*TTF_FontLineSkip(fuente)); if(posicion+16==5) break;
        case 6: printG(texto, fuente, "presentar  detalles  similares  a cualquier escala. Y es que todas estas", blanco,'n',45, 205+(n+5)*TTF_FontLineSkip(fuente)); if(posicion+16==6) break;
        case 7: printG(texto, fuente, "cosas  son  aproximadamente  fractales,  en  tanto  que  en  el sentido", blanco,'n',45, 205+(n+6)*TTF_FontLineSkip(fuente)); if(posicion+16==7) break;
        case 8: printG(texto, fuente, "matemático  estricto  un  fractal  tiene  detalles  en todas las escalas y", blanco,'n',45, 205+(n+7)*TTF_FontLineSkip(fuente)); if(posicion+16==8) break;
        case 9: printG(texto, fuente, "por  lo  tanto  resulta  autosimilar,  es  decir,  es posible ampliarlo infi-", blanco,'n',45, 205+(n+8)*TTF_FontLineSkip(fuente)); if(posicion+16==9) break;
        case 10: printG(texto, fuente, "nitamente  y  a  pesar  de ello seguir observando la misma estructura.", blanco,'n',45, 205+(n+9)*TTF_FontLineSkip(fuente)); if(posicion+16==10) break;
        case 11: printG(texto, fuente, "En  cambio,  con  los  objetos  naturales,  una  vez  que  se  alcanza  la", blanco,'n',45, 205+(n+10)*TTF_FontLineSkip(fuente)); if(posicion+16==11) break;
        case 12: printG(texto, fuente, "escala atómica ya no es posible aumentarlos más.", blanco,'n',45, 205+(n+11)*TTF_FontLineSkip(fuente)); if(posicion+16==12) break;
        case 13: printG(texto, fuente, "", blanco,'n',45, 205+(n+12)*TTF_FontLineSkip(fuente)); if(posicion+16==13) break;
        case 14: printG(texto, fuente, "La  denominación  de fractales (del latín fractus, irregular) al conjunto", blanco,'n',45, 205+(n+13)*TTF_FontLineSkip(fuente)); if(posicion+16==14) break;
        case 15: printG(texto, fuente, "de  estas  formas  generadas normalmente por procesos de iteración", blanco,'n',45, 205+(n+14)*TTF_FontLineSkip(fuente)); if(posicion+16==15) break;
        case 16: printG(texto, fuente, "sobre  vectores  complejos,  caracterizadas  por  ser  autosimilares  a", blanco,'n',45, 205+(n+15)*TTF_FontLineSkip(fuente)); if(posicion+16==16) break;
        case 17: printG(texto, fuente, "toda  escala,  tener  longitud  infinita,  por   no   ser   diferenciables   y", blanco,'n',45, 205+(n+16)*TTF_FontLineSkip(fuente)); if(posicion+16==17) break;
        case 18: printG(texto, fuente, "exhibir  una dimensión de Hausdorff fraccional, corresponde a Benoit", blanco,'n',45, 205+(n+17)*TTF_FontLineSkip(fuente)); if(posicion+16==18) break;
        case 19: printG(texto, fuente, "Mandelbrot  y  data  de  1975;  aunque  cabe   hacer   notar   que   hay", blanco,'n',45, 205+(n+18)*TTF_FontLineSkip(fuente)); if(posicion+16==19) break;
        case 20: printG(texto, fuente, "quienes  afirman  que  el  célebre  matemático  francés  del  siglo  XIX", blanco,'n',45, 205+(n+19)*TTF_FontLineSkip(fuente)); if(posicion+16==20) break;
        case 21: printG(texto, fuente, "Henri  Poincaré  no  lo  hizo  antes  porque en su época no existían las", blanco,'n',45, 205+(n+20)*TTF_FontLineSkip(fuente)); if(posicion+16==21) break;
        case 22: printG(texto, fuente, "computadoras.", blanco,'n',45, 205+(n+21)*TTF_FontLineSkip(fuente)); if(posicion+16==22) break;
        case 23: printG(texto, fuente, "", blanco,'n',45, 205+(n+22)*TTF_FontLineSkip(fuente)); if(posicion+16==23) break;
        case 24: printG(texto, fuente, "La  dimensión  de Hausdorff df es un cuantificador de hasta qué punto", blanco,'n',45, 205+(n+23)*TTF_FontLineSkip(fuente)); if(posicion+16==24) break;
        case 25: printG(texto, fuente, "el  objeto  geométrico cubre el espacio en que se encuentra inscrito y", blanco,'n',45, 205+(n+24)*TTF_FontLineSkip(fuente)); if(posicion+16==25) break;
        case 26: printG(texto, fuente, "se calcula como:", blanco,'n',45, 205+(n+25)*TTF_FontLineSkip(fuente)); if(posicion+16==26) break;
        case 27: printG(texto, fuente, "                       df  = log(N)/log(L/l)", blanco,'n',45, 205+(n+26)*TTF_FontLineSkip(fuente)); if(posicion+16==27) break;
        case 28: printG(texto, fuente, "", blanco,'n',45, 205+(n+27)*TTF_FontLineSkip(fuente)); if(posicion+16==28) break;
        case 29: printG(texto, fuente, "Donde  N  representa  el  número de secciones generadas después de", blanco,'n',45, 205+(n+28)*TTF_FontLineSkip(fuente)); if(posicion+16==29) break;
        case 30: printG(texto, fuente, "cada  iteración  y  L/l  resulta un indicador del número de veces que se", blanco,'n',45, 205+(n+29)*TTF_FontLineSkip(fuente)); if(posicion+16==30) break;
        case 31: printG(texto, fuente, "particiona  cada  uno  de los lados que constituyen la figura regular de", blanco,'n',45, 205+(n+30)*TTF_FontLineSkip(fuente)); if(posicion+16==31) break;
        case 32: printG(texto, fuente, "la  que  se  parte.  En  el caso del triángulo de Sierpinski, su dimensión", blanco,'n',45, 205+(n+31)*TTF_FontLineSkip(fuente)); if(posicion+16==32) break;
        case 33: printG(texto, fuente, "de Hausdorff está dada por:", blanco,'n',45, 205+(n+32)*TTF_FontLineSkip(fuente)); if(posicion+16==33) break;
        case 34: printG(texto, fuente, "                       df  = log(3)/log(2) = 1.58", blanco,'n',45, 205+(n+33)*TTF_FontLineSkip(fuente)); if(posicion+16==34) break;
        case 35: printG(texto, fuente, "", blanco,'n',45, 205+(n+34)*TTF_FontLineSkip(fuente)); if(posicion+16==35) break;
        case 36: printG(texto, fuente, "En  medida  de  que constituye el resultado de seccionar a toda escala", blanco,'n',45, 205+(n+35)*TTF_FontLineSkip(fuente)); if(posicion+16==36) break;
        case 37: printG(texto, fuente, "un  triángulo  equilátero  en  cuatro  particiones  similares cuyos lados", blanco,'n',45, 205+(n+36)*TTF_FontLineSkip(fuente)); if(posicion+16==37) break;
        case 38: printG(texto, fuente, "son  tan  sólo la mitad de los de la figura original y una vez hecho esto", blanco,'n',45, 205+(n+37)*TTF_FontLineSkip(fuente)); if(posicion+16==38) break;
        case 39: printG(texto, fuente, "se  extrae  la  sección central, de forma que queden las tres partes de", blanco,'n',45, 205+(n+38)*TTF_FontLineSkip(fuente)); if(posicion+16==39) break;
        case 40: printG(texto, fuente, "los vértices y sobre éstas se actúe de la misma manera.", blanco,'n',45, 205+(n+39)*TTF_FontLineSkip(fuente)); if(posicion+16==40) break;
        case 41: printG(texto, fuente, "", blanco,'n',45, 205+(n+40)*TTF_FontLineSkip(fuente)); if(posicion+16==41) break;
        case 42: printG(texto, fuente, "Para  construir  un  fractal  pueden  seguirse procedimientos matemá-", blanco,'n',45, 205+(n+41)*TTF_FontLineSkip(fuente)); if(posicion+16==42) break;
        case 43: printG(texto, fuente, "ticos,  geométricos,  físicos  y  químicos con el interés de hacer imáge-", blanco,'n',45, 205+(n+42)*TTF_FontLineSkip(fuente)); if(posicion+16==43) break;
        case 44: printG(texto, fuente, "nes,  modelos,  analizar  patrones  e  identificar  estructuras.  En cada", blanco,'n',45, 205+(n+43)*TTF_FontLineSkip(fuente)); if(posicion+16==44) break;
        case 45: printG(texto, fuente, "uno de los fractales elaborados podrá encontrar información referen-", blanco,'n',45, 205+(n+44)*TTF_FontLineSkip(fuente)); if(posicion+16==45) break;
        case 46: printG(texto, fuente, "te a su construcción.", blanco,'n',45, 205+(n+45)*TTF_FontLineSkip(fuente)); if(posicion+16==46) break;
      }
      break;
    case 2:  //
      maximo = 39;
      switch(posicion) {
        case 1: printG(texto, fuente, "Desde  la  definición  formal  de los fractales por Benoit Mandelbrot se", blanco,'n',45, 205+n*TTF_FontLineSkip(fuente)); if(posicion+16==1) break;
        case 2: printG(texto, fuente, "han identificado innumerables manifestaciones naturales de estructu-", blanco,'n',45, 205+(n+1)*TTF_FontLineSkip(fuente)); if(posicion+16==2) break;
        case 3: printG(texto, fuente, "ras  fractales.  Se sabe que su geometría está presente en depósitos y", blanco,'n',45, 205+(n+2)*TTF_FontLineSkip(fuente)); if(posicion+16==3) break;
        case 4: printG(texto, fuente, "agregados  coloidales,  poliméricos  y  electroquímicos;  en aparatos y", blanco,'n',45, 205+(n+3)*TTF_FontLineSkip(fuente)); if(posicion+16==4) break;
        case 5: printG(texto, fuente, "sistemas  biológicos,  como  los  vasos  capilares,   tubos   intestinales,", blanco,'n',45, 205+(n+4)*TTF_FontLineSkip(fuente)); if(posicion+16==5) break;
        case 6: printG(texto, fuente, "biliares,   bronquiales   y   en   las   redes   neuronales.   También  hay", blanco,'n',45, 205+(n+5)*TTF_FontLineSkip(fuente)); if(posicion+16==6) break;
        case 7: printG(texto, fuente, "evidencia  de  que la localización geográfica de epicentros en temblo-", blanco,'n',45, 205+(n+6)*TTF_FontLineSkip(fuente)); if(posicion+16==7) break;
        case 8: printG(texto, fuente, "res  exhibe  un  patrón  fractal  y  su  dimensión fraccional (dimensión", blanco,'n',45, 205+(n+7)*TTF_FontLineSkip(fuente)); if(posicion+16==8) break;
        case 9: printG(texto, fuente, "fractal) en la superficie irregular de una falla en un material ya se uti-", blanco,'n',45, 205+(n+8)*TTF_FontLineSkip(fuente)); if(posicion+16==9) break;
        case 10: printG(texto, fuente, "liza como medida indirecta de su resistencia y dureza.", blanco,'n',45, 205+(n+9)*TTF_FontLineSkip(fuente)); if(posicion+16==10) break;
        case 11: printG(texto, fuente, "", blanco,'n',45, 205+(n+10)*TTF_FontLineSkip(fuente)); if(posicion+16==11) break;
        case 12: printG(texto, fuente, "Los fractales mostraron por primera vez su utilidad cuando se generó", blanco,'n',45, 205+(n+11)*TTF_FontLineSkip(fuente)); if(posicion+16==12) break;
        case 13: printG(texto, fuente, "con  ellos  un  modelo  simple  para  la  aparición  de  ruido  en ciertas", blanco,'n',45, 205+(n+12)*TTF_FontLineSkip(fuente)); if(posicion+16==13) break;
        case 14: printG(texto, fuente, "líneas  de  transmisión en sistemas de comunicación digital. El análisis", blanco,'n',45, 205+(n+13)*TTF_FontLineSkip(fuente)); if(posicion+16==14) break;
        case 15: printG(texto, fuente, "de  las  señales  demostró   que  las   interrupciones   aparecían  como", blanco,'n',45, 205+(n+14)*TTF_FontLineSkip(fuente)); if(posicion+16==15) break;
        case 16: printG(texto, fuente, "paquetes,  pero dentro de estos paquetes se distinguía una estructura", blanco,'n',45, 205+(n+15)*TTF_FontLineSkip(fuente)); if(posicion+16==16) break;
        case 17: printG(texto, fuente, "intermitente  autosimilar  cuyo  registro  gráfico  dio lugar a un patrón", blanco,'n',45, 205+(n+16)*TTF_FontLineSkip(fuente)); if(posicion+16==17) break;
        case 18: printG(texto, fuente, "fractal  conocido  como  conjunto  o  polvo  de  Cantor;  el   cual   se  ha", blanco,'n',45, 205+(n+17)*TTF_FontLineSkip(fuente)); if(posicion+16==18) break;
        case 19: printG(texto, fuente, "utilizado  a su vez para representar desde la distribución heterogénea", blanco,'n',45, 205+(n+18)*TTF_FontLineSkip(fuente)); if(posicion+16==19) break;
        case 20: printG(texto, fuente, "de  los  anillos  de  Saturno y las fluctuaciones en el precio del algodón", blanco,'n',45, 205+(n+19)*TTF_FontLineSkip(fuente)); if(posicion+16==20) break;
        case 21: printG(texto, fuente, "desde  el  siglo  pasado,  hasta las variaciones en el nivel de las aguas", blanco,'n',45, 205+(n+20)*TTF_FontLineSkip(fuente)); if(posicion+16==21) break;
        case 22: printG(texto, fuente, "del  río  Nilo. Además, cuando la idea que subyace tras la construcción", blanco,'n',45, 205+(n+21)*TTF_FontLineSkip(fuente)); if(posicion+16==22) break;
        case 23: printG(texto, fuente, "de  este  conjunto  se  extiende  a  tres  dimensiones,  el patrón que se", blanco,'n',45, 205+(n+22)*TTF_FontLineSkip(fuente)); if(posicion+16==23) break;
        case 24: printG(texto, fuente, "genera  coincide  con  la  distribución  de  estrellas  y   galaxias   en   el", blanco,'n',45, 205+(n+23)*TTF_FontLineSkip(fuente)); if(posicion+16==24) break;
        case 25: printG(texto, fuente, "Universo.", blanco,'n',45, 205+(n+24)*TTF_FontLineSkip(fuente)); if(posicion+16==25) break;
        case 26: printG(texto, fuente, "", blanco,'n',45, 205+(n+25)*TTF_FontLineSkip(fuente)); if(posicion+16==26) break;
        case 27: printG(texto, fuente, "En  general,   los   atractores   extraños   de   los   sistemas   dinámicos", blanco,'n',45, 205+(n+26)*TTF_FontLineSkip(fuente)); if(posicion+16==27) break;
        case 28: printG(texto, fuente, "caóticos,  con  sus  dobleces  interminables,  también son fractales. Su", blanco,'n',45, 205+(n+27)*TTF_FontLineSkip(fuente)); if(posicion+16==28) break;
        case 29: printG(texto, fuente, "geometría  complicada  e  irregular  se  refleja  en el comportamiento", blanco,'n',45, 205+(n+28)*TTF_FontLineSkip(fuente)); if(posicion+16==29) break;
        case 30: printG(texto, fuente, "dinámico complicado e irregular de los fenómenos caóticos.", blanco,'n',45, 205+(n+29)*TTF_FontLineSkip(fuente)); if(posicion+16==30) break;
        case 31: printG(texto, fuente, "", blanco,'n',45, 205+(n+30)*TTF_FontLineSkip(fuente)); if(posicion+16==31) break;
        case 32: printG(texto, fuente, "Es  de  vital  importancia  señalar  que  los  fractales  que existen en la", blanco,'n',45, 205+(n+31)*TTF_FontLineSkip(fuente)); if(posicion+16==32) break;
        case 33: printG(texto, fuente, "naturaleza  tienden  a  ser  irregulares  y  son   autosimilares   sólo  en", blanco,'n',45, 205+(n+32)*TTF_FontLineSkip(fuente)); if(posicion+16==33) break;
        case 34: printG(texto, fuente, "sentido  estadístico;  es  decir,  si  se elige un conjunto suficientemente", blanco,'n',45, 205+(n+33)*TTF_FontLineSkip(fuente)); if(posicion+16==34) break;
        case 35: printG(texto, fuente, "grande  de  objetos  de  la misma clase y amplificamos una porción de", blanco,'n',45, 205+(n+34)*TTF_FontLineSkip(fuente)); if(posicion+16==35) break;
        case 36: printG(texto, fuente, "alguno  de  ellos,  es  posible  que  no   sea   idéntico  al  original,  pero", blanco,'n',45, 205+(n+35)*TTF_FontLineSkip(fuente)); if(posicion+16==36) break;
        case 37: printG(texto, fuente, "seguramente  sí  será  similar  a  algún  otro  miembro de la colección.", blanco,'n',45, 205+(n+36)*TTF_FontLineSkip(fuente)); if(posicion+16==37) break;
        case 38: printG(texto, fuente, "", blanco,'n',45, 205+(n+32)*TTF_FontLineSkip(fuente)); if(posicion+16==38) break;
        case 39: printG(texto, fuente, "Asimismo,  su  dimensión  es  fraccional   pero  se   obtiene  realizando", blanco,'n',45, 205+(n+38)*TTF_FontLineSkip(fuente)); if(posicion+16==39) break;
        case 40: printG(texto, fuente, "promedios  sobre  sus  valores  en  muchas  regiones  y  para muchos", blanco,'n',45, 205+(n+39)*TTF_FontLineSkip(fuente)); if(posicion+16==40) break;
        case 41: printG(texto, fuente, "cuerpos  del  mismo tipo. Cuando se amplifica alguna de las partes de", blanco,'n',45, 205+(n+40)*TTF_FontLineSkip(fuente)); if(posicion+16==41) break;
        case 42: printG(texto, fuente, "un  fractal  natural,  la  propiedad  de  generar  la  misma  figura tiene", blanco,'n',45, 205+(n+41)*TTF_FontLineSkip(fuente)); if(posicion+16==42) break;
        case 43: printG(texto, fuente, "límites  inferiores  y superiores. Por ejemplo, el tamaño de los objetos", blanco,'n',45, 205+(n+42)*TTF_FontLineSkip(fuente)); if(posicion+16==43) break;
        case 44: printG(texto, fuente, "más   grandes   que   se   pueden   observar   en   una   montaña   está", blanco,'n',45, 205+(n+43)*TTF_FontLineSkip(fuente)); if(posicion+16==44) break;
        case 45: printG(texto, fuente, "determinado  por   la  fuerza  de  gravedad,  mientras  que  la  menor", blanco,'n',45, 205+(n+44)*TTF_FontLineSkip(fuente)); if(posicion+16==45) break;
        case 46: printG(texto, fuente, "escala  de   observación  a  la  cual  todavía  se  detectan  los  mismos", blanco,'n',45, 205+(n+45)*TTF_FontLineSkip(fuente)); if(posicion+16==46) break;
        case 47: printG(texto, fuente, "detalles,  depende  de  la  acción  de  la  erosión  y  del  tamaño de los", blanco,'n',45, 205+(n+46)*TTF_FontLineSkip(fuente)); if(posicion+16==47) break;
        case 48: printG(texto, fuente, "átomos.  Los  fractales resultan, en este caso, buenas aproximaciones", blanco,'n',45, 205+(n+47)*TTF_FontLineSkip(fuente)); if(posicion+16==48) break;
        case 49: printG(texto, fuente, "de la estructura de las formas naturales.", blanco,'n',45, 205+(n+48)*TTF_FontLineSkip(fuente)); if(posicion+16==49) break;
      }
      break;
    case 3:
      maximo = 15;
      switch(posicion) {
        case 1: printG(texto, fuente, "Aunque es difícil aceptar la idea de enfrentarse a curvas de longitud", blanco,'n',45, 205+n*TTF_FontLineSkip(fuente)); if(posicion+16==1) break;
        case 2: printG(texto, fuente, "infinita que no se extienden en todo el espacio o con objetos de", blanco,'n',45, 205+(n+1)*TTF_FontLineSkip(fuente)); if(posicion+16==2) break;
        case 3: printG(texto, fuente, "dimensión fraccional cuyas representaciones visuales con la", blanco,'n',45, 205+(n+2)*TTF_FontLineSkip(fuente)); if(posicion+16==3) break;
        case 4: printG(texto, fuente, "asistencia de la computadora nos dejan perplejos; es posible que", blanco,'n',45, 205+(n+3)*TTF_FontLineSkip(fuente)); if(posicion+16==4) break;
        case 5: printG(texto, fuente, "resulte aún más escalofriante entender que en realidad nos estamos", blanco,'n',45, 205+(n+4)*TTF_FontLineSkip(fuente)); if(posicion+16==5) break;
        case 6: printG(texto, fuente, "topando con un conjunto de vectores generado a partir de la", blanco,'n',45, 205+(n+5)*TTF_FontLineSkip(fuente)); if(posicion+16==6) break;
        case 7: printG(texto, fuente, "aplicación de transformaciones para rotar, trasladar, escalar y", blanco,'n',45, 205+(n+6)*TTF_FontLineSkip(fuente)); if(posicion+16==7) break;
        case 8: printG(texto, fuente, "deformar cualquier figura a voluntad. Los ejemplos más claros de", blanco,'n',45, 205+(n+7)*TTF_FontLineSkip(fuente)); if(posicion+16==8) break;
        case 9: printG(texto, fuente, "ello constituyen la generación de nuestros modelos para el triángulo", blanco,'n',45, 205+(n+8)*TTF_FontLineSkip(fuente)); if(posicion+16==9) break;
        case 10: printG(texto, fuente, "de Sierpinski, el helecho y el arbusto presentados.", blanco,'n',45, 205+(n+9)*TTF_FontLineSkip(fuente)); if(posicion+16==10) break;
        case 11: printG(texto, fuente, "", blanco,'n',45, 205+(n+11)*TTF_FontLineSkip(fuente)); if(posicion+16==11) break;
        case 12: printG(texto, fuente, "La idea se basa en tomar un número sobre el que se hace una", blanco,'n',45, 205+(n+11)*TTF_FontLineSkip(fuente)); if(posicion+16==12) break;
        case 13: printG(texto, fuente, "transformación (que puede o no ser lineal), repetir lo mismo con el", blanco,'n',45, 205+(n+12)*TTF_FontLineSkip(fuente)); if(posicion+16==13) break;
        case 14: printG(texto, fuente, "resultado y continuar haciéndolo indefinidamente en los siguientes", blanco,'n',45, 205+(n+13)*TTF_FontLineSkip(fuente)); if(posicion+16==14) break;
        case 15: printG(texto, fuente, "resultados obtenidos. Formalmente se dice que se hace una iteración", blanco,'n',45, 205+(n+14)*TTF_FontLineSkip(fuente)); if(posicion+16==15) break;
        case 16: printG(texto, fuente, "y se representa como:", blanco,'n',45, 205+(n+15)*TTF_FontLineSkip(fuente)); if(posicion+16==16) break;
        case 17: printG(texto, fuente, "", blanco,'n',45, 205+(n+17)*TTF_FontLineSkip(fuente)); if(posicion+16==17) break;
        case 18: printG(texto, fuente, "            X_(n+1) = f(X_n)", blanco,'n',45, 205+(n+17)*TTF_FontLineSkip(fuente)); if(posicion+16==18) break;
        case 19: printG(texto, fuente, "", blanco,'n',45, 205+(n+18)*TTF_FontLineSkip(fuente)); if(posicion+16==19) break;
        case 20: printG(texto, fuente, "La secuencia de números que se genera con la iteración se", blanco,'n',45, 205+(n+19)*TTF_FontLineSkip(fuente)); if(posicion+16==20) break;
        case 21: printG(texto, fuente, "denomina órbita y al punto al que se tiende llegar se le llama su", blanco,'n',45, 205+(n+20)*TTF_FontLineSkip(fuente)); if(posicion+16==21) break;
        case 22: printG(texto, fuente, "atractor. ", blanco,'n',45, 205+(n+21)*TTF_FontLineSkip(fuente)); if(posicion+16==22) break;
        case 23: printG(texto, fuente, "", blanco,'n',45, 205+(n+22)*TTF_FontLineSkip(fuente)); if(posicion+16==23) break;
        case 24: printG(texto, fuente, "Una vez elegida una transformación a iterar, sólo queda decidir con", blanco,'n',45, 205+(n+23)*TTF_FontLineSkip(fuente)); if(posicion+16==24) break;
        case 25: printG(texto, fuente, "qué espacio vectorial se va a trabajar.", blanco,'n',45, 205+(n+24)*TTF_FontLineSkip(fuente)); if(posicion+16==25) break;
      }
      break;
    case 4:    //Creditos
      maximo = 23;
      switch(posicion) {
        case 1: printG(texto, fuente, "Esperamos que este trabajo contribuya a develar para sus usuarios la", blanco,'n',45, 205+n*TTF_FontLineSkip(fuente)); if(posicion+16==1) break;
        case 2: printG(texto, fuente, "belleza del orden que puede encontrarse vinculada a los números; en", blanco,'n',45, 205+(n+1)*TTF_FontLineSkip(fuente)); if(posicion+16==2) break;
        case 3: printG(texto, fuente, "medida de que todas las imágenes desplegadas no son más que la", blanco,'n',45, 205+(n+2)*TTF_FontLineSkip(fuente)); if(posicion+16==3) break;
        case 4: printG(texto, fuente, "representación de un  conjunto de vectores que obedecen a", blanco,'n',45, 205+(n+3)*TTF_FontLineSkip(fuente)); if(posicion+16==4) break;
        case 5: printG(texto, fuente, "operaciones de afinidad específicas. ", blanco,'n',45, 205+(n+4)*TTF_FontLineSkip(fuente)); if(posicion+16==5) break;
        case 6: printG(texto, fuente, "", blanco,'n',45, 205+(n+5)*TTF_FontLineSkip(fuente)); if(posicion+16==6) break;
        case 7: printG(texto, fuente, "Agradecemos profundamente al Fis. Sergio Arzamendi Pérez por", blanco,'n',45, 205+(n+6)*TTF_FontLineSkip(fuente)); if(posicion+16==7) break;
        case 8: printG(texto, fuente, "encaminarnos hacia  la idea de la elaboración de este proyecto.  ", blanco,'n',45, 205+(n+7)*TTF_FontLineSkip(fuente)); if(posicion+16==8) break;
        case 9: printG(texto, fuente, "Sugerimos la lectura de la referencia bibliográfica que hizo posible el", blanco,'n',45, 205+(n+8)*TTF_FontLineSkip(fuente)); if(posicion+16==9) break;
        case 10: printG(texto, fuente, "desarrollo de esta aplicación: ", blanco,'n',45, 205+(n+9)*TTF_FontLineSkip(fuente)); if(posicion+16==10) break;
        case 11: printG(texto, fuente, "", blanco,'n',45, 205+(n+10)*TTF_FontLineSkip(fuente)); if(posicion+16==11) break;
        case 12: printG(texto, fuente, "Talanquer, Vicente. \"Fractus, Fracta, Fractal: Fractales, de laberintos y", blanco,'n',45, 205+(n+11)*TTF_FontLineSkip(fuente)); if(posicion+16==12) break;
        case 13: printG(texto, fuente, "espejos.\" México, FCE,1996. ", blanco,'n',45, 205+(n+12)*TTF_FontLineSkip(fuente)); if(posicion+16==13) break;
        case 14: printG(texto, fuente, "", blanco,'n',45, 205+(n+13)*TTF_FontLineSkip(fuente)); if(posicion+16==14) break;
        case 15: printG(texto, fuente, "Miguel Barousse Ordóñez <miguelbo@gmail.com>", blanco,'n',45, 205+(n+14)*TTF_FontLineSkip(fuente)); if(posicion+16==15) break;
        case 16: printG(texto, fuente, "Octavio Narváez Aroche <ocnaar@yahoo.com>", blanco,'n',45, 205+(n+15)*TTF_FontLineSkip(fuente)); if(posicion+16==16) break;
        case 17: printG(texto, fuente, "", blanco,'n',45, 205+(n+16)*TTF_FontLineSkip(fuente)); if(posicion+16==17) break;
        case 18: printG(texto, fuente, "México D.F, Ciudad Universitaria a 17 de Junio de 2004.  ", blanco,'n',45, 205+(n+17)*TTF_FontLineSkip(fuente)); if(posicion+16==18) break;
        case 19: printG(texto, fuente, "", blanco,'n',45, 205+(n+18)*TTF_FontLineSkip(fuente)); if(posicion+16==19) break;
        case 20: printG(texto, fuente, "Este programa está protegido por la licencia GNU General Public Licence", blanco,'n',45, 205+(n+19)*TTF_FontLineSkip(fuente)); if(posicion+16==20) break;
        case 21: printG(texto, fuente, "(GPL). Esta licencia le da los derechos de redistribuir y/o modificar la", blanco,'n',45, 205+(n+20)*TTF_FontLineSkip(fuente)); if(posicion+16==21) break;
        case 22: printG(texto, fuente, "presente obra, según los términos que ésta estipula. Puede ver el archivo", blanco,'n',45, 205+(n+21)*TTF_FontLineSkip(fuente)); if(posicion+16==22) break;
        case 23: printG(texto, fuente, "anexo COPYING.txt para conocer sus derechos completos.", blanco,'n',45, 205+(n+22)*TTF_FontLineSkip(fuente)); if(posicion+16==23) break;
        case 24: printG(texto, fuente, "", blanco,'n',45, 205+(n+23)*TTF_FontLineSkip(fuente)); if(posicion+16==24) break;
        case 25: printG(texto, fuente, "", blanco,'n',45, 205+(n+24)*TTF_FontLineSkip(fuente)); if(posicion+16==25) break;
        case 26: printG(texto, fuente, "Este programa utiliza la librería gráfica SDL (Simple DirectMedia Layer), la", blanco,'n',45, 205+(n+25)*TTF_FontLineSkip(fuente)); if(posicion+16==26) break;
        case 27: printG(texto, fuente, "cual está licenciada bajo los términos de la GNU Lesser General Public", blanco,'n',45, 205+(n+26)*TTF_FontLineSkip(fuente)); if(posicion+16==27) break;
        case 28: printG(texto, fuente, "Licence (LGPL), incluida en el archivo SDL_LICENCE.txt. Si desea obtener el", blanco,'n',45, 205+(n+27)*TTF_FontLineSkip(fuente)); if(posicion+16==28) break;
        case 29: printG(texto, fuente, "código fuente de esta librería, nos lo puede solicitar a través de nuestros", blanco,'n',45, 205+(n+28)*TTF_FontLineSkip(fuente)); if(posicion+16==29) break;
        case 30: printG(texto, fuente, "correos electrónicos o puede descargarla de <http://www.libsdl.org>.", blanco,'n',45, 205+(n+29)*TTF_FontLineSkip(fuente)); if(posicion+16==30) break;
        case 31: printG(texto, fuente, "", blanco,'n',45, 205+(n+30)*TTF_FontLineSkip(fuente)); if(posicion+16==31) break;
        case 32: printG(texto, fuente, "Los iconos utilizados en este programa pertenecen al set de iconos Crystal", blanco,'n',45, 205+(n+31)*TTF_FontLineSkip(fuente)); if(posicion+16==32) break;
        case 33: printG(texto, fuente, "SVG, los cuales fueron creados por Everaldo <http://www.everaldo.com>.", blanco,'n',45, 205+(n+32)*TTF_FontLineSkip(fuente)); if(posicion+16==33) break;      }
      break;
    case 5:    //Ayuda
      maximo = 33;
      switch(posicion) {
        case 1: printG(texto, fuente, "Navegación por los fractales", blanco,'b',45, 205+n*TTF_FontLineSkip(fuente));
                if(posicion+16==1) break;
        case 2: printG(texto, fuente, "", blanco,'n',45, 205+(n+1)*TTF_FontLineSkip(fuente));
                if(posicion+16==2) break;
        case 3: printG(texto, fuente, "Se incluyen dos formas de navegar por los fractales de Mandelbrot y Julia.", blanco,'n',45, 205+(n+2)*TTF_FontLineSkip(fuente));
                if(posicion+16==3) break;
        case 4: printG(texto, fuente, "La primera consiste en la utilización del ratón, y la segunda empleando los", blanco,'n',45, 205+(n+3)*TTF_FontLineSkip(fuente));
                if(posicion+16==4) break;
        case 5: printG(texto, fuente, "iconos que aparecen en la esquina inferior derecha de la pantalla en la que", blanco,'n',45, 205+(n+4)*TTF_FontLineSkip(fuente));
                if(posicion+16==5) break;
        case 6: printG(texto, fuente, "se generan los fractales. Ambas formas se complementan con el teclado.", blanco,'n',45, 205+(n+5)*TTF_FontLineSkip(fuente));
                if(posicion+16==6) break;
        case 7: printG(texto, fuente, "", blanco,'n',45, 205+(n+6)*TTF_FontLineSkip(fuente));
                if(posicion+16==7) break;
        case 8: printG(texto, fuente, "El sistema de navegación permite realizar las siguientes acciones:", blanco,'n',45, 205+(n+7)*TTF_FontLineSkip(fuente));
                if(posicion+16==8) break;
        case 9: printG(texto, fuente, "", blanco,'n',45, 205+(n+8)*TTF_FontLineSkip(fuente));
                if(posicion+16==9) break;
        case 10: printG(texto, fuente, "Acercamientos:", blanco,'b',45, 205+(n+9)*TTF_FontLineSkip(fuente));
                if(posicion+16==10) break;
        case 11: printG(texto, fuente, "  Con el ratón: Cuando se hace clic izquierdo en algún punto de la pantalla,", blanco,'n',45, 205+(n+10)*TTF_FontLineSkip(fuente));
                if(posicion+16==11) break;
        case 12: printG(texto, fuente, "  este punto se coloca en el centro de la misma, y se aumenta la escala.", blanco,'n',45, 205+(n+11)*TTF_FontLineSkip(fuente));
                if(posicion+16==12) break;
        case 13: printG(texto, fuente, "  Con los iconos: Si se hace clic en el icono de una lupa con el signo +, se", blanco,'n',45, 205+(n+12)*TTF_FontLineSkip(fuente));
                if(posicion+16==13) break;
        case 14: printG(texto, fuente, "  aumenta la escala, sin hacer ningún desplazamiento.", blanco,'n',45, 205+(n+13)*TTF_FontLineSkip(fuente));
                if(posicion+16==14) break;
        case 15: printG(texto, fuente, "", blanco,'n',45, 205+(n+14)*TTF_FontLineSkip(fuente));
                if(posicion+16==15) break;
        case 16: printG(texto, fuente, "Alejamientos:", blanco,'b',45, 205+(n+15)*TTF_FontLineSkip(fuente));
                if(posicion+16==16) break;
        case 17: printG(texto, fuente, "  Con el ratón: Cuando se hace clic derecho en algún punto de la pantalla,", blanco,'n',45, 205+(n+16)*TTF_FontLineSkip(fuente));
                if(posicion+16==17) break;
        case 18: printG(texto, fuente, "  este punto se coloca en el centro de la misma, y se disminuye la escala.", blanco,'n',45, 205+(n+17)*TTF_FontLineSkip(fuente)); 
                if(posicion+16==18) break;
        case 19: printG(texto, fuente, "  Con los iconos: Si se hace clic en el icono de una lupa con el signo -, se", blanco,'n',45, 205+(n+18)*TTF_FontLineSkip(fuente));
                if(posicion+16==19) break;
        case 20: printG(texto, fuente, "  disminuye la escala, sin hacer ningún desplazamiento.", blanco,'n',45, 205+(n+19)*TTF_FontLineSkip(fuente));
                if(posicion+16==20) break;
        case 21: printG(texto, fuente, "", blanco,'n',45, 205+(n+20)*TTF_FontLineSkip(fuente));
                if(posicion+16==21) break;
        case 22: printG(texto, fuente, "Es posible modificar la escala con la que se realiza cada nivel de zoom", blanco,'n',45, 205+(n+21)*TTF_FontLineSkip(fuente));
                if(posicion+16==22) break;
        case 23: printG(texto, fuente, "mediante la utilización de las teclas + ó -. Si se presiona la primera, se", blanco,'n',45, 205+(n+22)*TTF_FontLineSkip(fuente));
                if(posicion+16==23) break;
        case 24: printG(texto, fuente, "aumenta la escala con la que se realiza el zoom, y la segunda la disminuye.", blanco,'n',45, 205+(n+23)*TTF_FontLineSkip(fuente));
                if(posicion+16==24) break;
        case 25: printG(texto, fuente, "", blanco,'n',45, 205+(n+24)*TTF_FontLineSkip(fuente));
                if(posicion+16==25) break;
        case 26: printG(texto, fuente, "Desplazamientos:", blanco,'b',45, 205+(n+25)*TTF_FontLineSkip(fuente));
                if(posicion+16==26) break;
        case 27: printG(texto, fuente, "  Con el ratón: Si se presiona el botón central del ratón (si existe), el", blanco,'n',45, 205+(n+26)*TTF_FontLineSkip(fuente));
                if(posicion+16==27) break;
        case 28: printG(texto, fuente, "  punto al que se le haya hecho clic se coloca en el centro de la pantalla.", blanco,'n',45, 205+(n+27)*TTF_FontLineSkip(fuente));
                if(posicion+16==28) break;
        case 29: printG(texto, fuente, "", blanco,'n',45, 205+(n+28)*TTF_FontLineSkip(fuente));
                if(posicion+16==29) break;
        case 30: printG(texto, fuente, "Restaurar las condiciones iniciales:", blanco,'b',45, 205+(n+29)*TTF_FontLineSkip(fuente));
                if(posicion+16==30) break;
        case 31: printG(texto, fuente, "  Se logra al presionar el icono que muestra una flecha curva, o si se", blanco,'n',45, 205+(n+30)*TTF_FontLineSkip(fuente));
                if(posicion+16==31) break;
        case 32: printG(texto, fuente, "  presiona la barra espaciadora.", blanco,'n',45, 205+(n+31)*TTF_FontLineSkip(fuente));
                if(posicion+16==32) break;
        case 33: printG(texto, fuente, "", blanco,'n',45, 205+(n+32)*TTF_FontLineSkip(fuente));
                if(posicion+16==33) break;
        case 34: printG(texto, fuente, "Cambiar de fractal:", blanco,'b',45, 205+(n+33)*TTF_FontLineSkip(fuente));
                if(posicion+16==34) break;
        case 35: printG(texto, fuente, "  Si se encuentra en alguno de los tres fractales siguientes: conjunto de", blanco,'n',45, 205+(n+34)*TTF_FontLineSkip(fuente));
                if(posicion+16==35) break;
        case 36: printG(texto, fuente, "  Mandelbrot, conjuntos de Julia, o conjuntos de Julia y Mandelbrot; es", blanco,'n',45, 205+(n+35)*TTF_FontLineSkip(fuente));
                if(posicion+16==36) break;
        case 37: printG(texto, fuente, "  posible ciclar entre estos fractales presionando la tecla derecha del", blanco,'n',45, 205+(n+36)*TTF_FontLineSkip(fuente));
                if(posicion+16==37) break;
        case 38: printG(texto, fuente, "  teclado, o haciendo clic en el icono de flecha derecha.", blanco,'n',45, 205+(n+37)*TTF_FontLineSkip(fuente));
                if(posicion+16==38) break;
        case 39: printG(texto, fuente, "", blanco,'n',45, 205+(n+38)*TTF_FontLineSkip(fuente));
                if(posicion+16==39) break;
        case 40: printG(texto, fuente, "Cambiar la paleta de colores:", blanco,'b',45, 205+(n+39)*TTF_FontLineSkip(fuente));
                if(posicion+16==40) break;
        case 41: printG(texto, fuente, "  Puede cambiar la paleta de colores en la ventana Opciones, la cual se", blanco,'n',45, 205+(n+40)*TTF_FontLineSkip(fuente));
                if(posicion+16==41) break;
        case 42: printG(texto, fuente, "  accede desde el menu principal, o con el icono que tiene forma de paleta", blanco,'n',45, 205+(n+41)*TTF_FontLineSkip(fuente));
                if(posicion+16==42) break;
        case 43: printG(texto, fuente, "  de colores dentro de la ventana generadora del fractal.", blanco,'n',45, 205+(n+42)*TTF_FontLineSkip(fuente));
                if(posicion+16==43) break;



      }
      break;
    case 6:    //Mandelbrot
      maximo = 44;
      switch(posicion) {
        case 1: printG(texto, fuente, "Para continuar sus investigaciones en torno a los fractales, Benoit", blanco,'n',45, 205+n*TTF_FontLineSkip(fuente)); if(posicion+16==1) break;
        case 2: printG(texto, fuente, "Mandelbrot recuperó el análisis de las iteraciones con números", blanco,'n',45, 205+(n+1)*TTF_FontLineSkip(fuente)); if(posicion+16==2) break;
        case 3: printG(texto, fuente, "complejos elaborado por Gaston Julia y Pierre Fatou a principios del", blanco,'n',45, 205+(n+2)*TTF_FontLineSkip(fuente)); if(posicion+16==3) break;
        case 4: printG(texto, fuente, "siglo XX; especialmente cuando la iteración consiste en elevarlos al", blanco,'n',45, 205+(n+3)*TTF_FontLineSkip(fuente)); if(posicion+16==4) break;
        case 5: printG(texto, fuente, "cuadrado y sumar una constante c:", blanco,'n',45, 205+(n+4)*TTF_FontLineSkip(fuente)); if(posicion+16==5) break;
        case 6: printG(texto, fuente, "                       Z_(n+1) = Z_n^2 + c", blanco,'n',45, 205+(n+5)*TTF_FontLineSkip(fuente)); if(posicion+16==6) break;
        case 7: printG(texto, fuente, "", blanco,'n',45, 205+(n+6)*TTF_FontLineSkip(fuente)); if(posicion+16==7) break;
        case 8: printG(texto, fuente, "Lo interesante de la iteración consiste en el hecho de que a cada valor", blanco,'n',45, 205+(n+7)*TTF_FontLineSkip(fuente)); if(posicion+16==8) break;
        case 9: printG(texto, fuente, "de c corresponde una órbita distinta en cada iteración y que sólo un", blanco,'n',45, 205+(n+8)*TTF_FontLineSkip(fuente)); if(posicion+16==9) break;
        case 10: printG(texto, fuente, "conjunto bien definido del plano complejo genera órbitas periódicas", blanco,'n',45, 205+(n+9)*TTF_FontLineSkip(fuente)); if(posicion+16==10) break;
        case 11: printG(texto, fuente, "que escapan hacia atractores finitos.", blanco,'n',45, 205+(n+10)*TTF_FontLineSkip(fuente)); if(posicion+16==11) break;
        case 12: printG(texto, fuente, "Todos estos puntos “prisioneros” en la iteración pertenecen a lo que", blanco,'n',45, 205+(n+11)*TTF_FontLineSkip(fuente)); if(posicion+16==12) break;
        case 13: printG(texto, fuente, "hoy en día se le denomina el cuerpo de un “Conjunto de Julia” . El", blanco,'n',45, 205+(n+12)*TTF_FontLineSkip(fuente)); if(posicion+16==13) break;
        case 14: printG(texto, fuente, "conjunto en sí, sólo está conformado por la curva que separa a los", blanco,'n',45, 205+(n+13)*TTF_FontLineSkip(fuente)); if(posicion+16==14) break;
        case 15: printG(texto, fuente, "puntos prisioneros de los escapistas, esto es, de aquellos que generan", blanco,'n',45, 205+(n+14)*TTF_FontLineSkip(fuente)); if(posicion+16==15) break;
        case 16: printG(texto, fuente, "órbitas que escapan al infinito en la iteración; aunque los puntos", blanco,'n',45, 205+(n+15)*TTF_FontLineSkip(fuente)); if(posicion+16==16) break;
        case 17: printG(texto, fuente, "\"dentro\" del Conjunto de Julia también son prisioneros.     ", blanco,'n',45, 205+(n+16)*TTF_FontLineSkip(fuente)); if(posicion+16==17) break;
        case 18: printG(texto, fuente, "", blanco,'n',45, 205+(n+17)*TTF_FontLineSkip(fuente)); if(posicion+16==18) break;
        case 19: printG(texto, fuente, "Una observación cuidadosa del borde de la figura trazada sobre el", blanco,'n',45, 205+(n+18)*TTF_FontLineSkip(fuente)); if(posicion+16==19) break;
        case 20: printG(texto, fuente, "plano complejo revela un hecho fundamental: la frontera o conjunto", blanco,'n',45, 205+(n+19)*TTF_FontLineSkip(fuente)); if(posicion+16==20) break;
        case 21: printG(texto, fuente, "de Julia es un fractal y la curva total puede ser regenerada por", blanco,'n',45, 205+(n+20)*TTF_FontLineSkip(fuente)); if(posicion+16==21) break;
        case 22: printG(texto, fuente, "cualquier trozo que de ella se elija a cualquier escala. Sólo aplique un", blanco,'n',45, 205+(n+21)*TTF_FontLineSkip(fuente)); if(posicion+16==22) break;
        case 23: printG(texto, fuente, "acercamiento a las imágenes en su monitor para comprobarlo y", blanco,'n',45, 205+(n+22)*TTF_FontLineSkip(fuente)); if(posicion+16==23) break;
        case 24: printG(texto, fuente, "recorra los “laberintos de un mundo infinitamente repetido, que de", blanco,'n',45, 205+(n+23)*TTF_FontLineSkip(fuente)); if(posicion+16==24) break;
        case 25: printG(texto, fuente, "nuevo tiene longitud infinita y dimensión fraccional” (Talanquer).", blanco,'n',45, 205+(n+24)*TTF_FontLineSkip(fuente)); if(posicion+16==25) break;
        case 26: printG(texto, fuente, "", blanco,'n',45, 205+(n+25)*TTF_FontLineSkip(fuente)); if(posicion+16==26) break;
        case 27: printG(texto, fuente, "Ante un mundo de posibilidades infinitas como éste, surge la", blanco,'n',45, 205+(n+26)*TTF_FontLineSkip(fuente)); if(posicion+16==27) break;
        case 28: printG(texto, fuente, "necesidad de intentar hacer una clasificación; de ahí que se hable de", blanco,'n',45, 205+(n+27)*TTF_FontLineSkip(fuente)); if(posicion+16==28) break;
        case 29: printG(texto, fuente, "Conjuntos de Julia Conexos para referirse a los que están formados", blanco,'n',45, 205+(n+28)*TTF_FontLineSkip(fuente)); if(posicion+16==29) break;
        case 30: printG(texto, fuente, "por una sola pieza y Cuerpos Disconexos para los que se encuentran", blanco,'n',45, 205+(n+29)*TTF_FontLineSkip(fuente)); if(posicion+16==30) break;
        case 31: printG(texto, fuente, "desmembrados en infinitas colecciones de puntos más o menos", blanco,'n',45, 205+(n+30)*TTF_FontLineSkip(fuente)); if(posicion+16==31) break;
        case 32: printG(texto, fuente, "aisladas.", blanco,'n',45, 205+(n+31)*TTF_FontLineSkip(fuente)); if(posicion+16==32) break;
        case 33: printG(texto, fuente, "", blanco,'n',45, 205+(n+32)*TTF_FontLineSkip(fuente)); if(posicion+16==33) break;
        case 34: printG(texto, fuente, "Esta distinción geométrica da pie a que los valores del parámetro", blanco,'n',45, 205+(n+33)*TTF_FontLineSkip(fuente)); if(posicion+16==34) break;
        case 35: printG(texto, fuente, "complejo c sean separados en dos conjuntos bien diferenciados: los", blanco,'n',45, 205+(n+34)*TTF_FontLineSkip(fuente)); if(posicion+16==35) break;
        case 36: printG(texto, fuente, "que en la iteración Z_(n+1)=Z_n^2 +c dan lugar a figuras conexas, y", blanco,'n',45, 205+(n+35)*TTF_FontLineSkip(fuente)); if(posicion+16==36) break;
        case 37: printG(texto, fuente, "aquellos que en la misma generan formas disconexas. Aprovechando", blanco,'n',45, 205+(n+36)*TTF_FontLineSkip(fuente)); if(posicion+16==37) break;
        case 38: printG(texto, fuente, "las propiedades de la iteración cuadrática, Benoit Mandelbrot se", blanco,'n',45, 205+(n+37)*TTF_FontLineSkip(fuente)); if(posicion+16==38) break;
        case 39: printG(texto, fuente, "dedicó a localizar los valores de c que dan lugar a Conjuntos de Julia", blanco,'n',45, 205+(n+38)*TTF_FontLineSkip(fuente)); if(posicion+16==39) break;
        case 40: printG(texto, fuente, "Conexos y al hacerlo se encontró con que dicho conjunto de valores", blanco,'n',45, 205+(n+39)*TTF_FontLineSkip(fuente)); if(posicion+16==40) break;
        case 41: printG(texto, fuente, "también tenía una estructura conexa sorprendente cuando se", blanco,'n',45, 205+(n+40)*TTF_FontLineSkip(fuente)); if(posicion+16==41) break;
        case 42: printG(texto, fuente, "representaba sobre el plano complejo: una forma cardioide tangente", blanco,'n',45, 205+(n+41)*TTF_FontLineSkip(fuente)); if(posicion+16==42) break;
        case 43: printG(texto, fuente, "a un disco circular de menor extensión de la que brotan una infinidad", blanco,'n',45, 205+(n+42)*TTF_FontLineSkip(fuente)); if(posicion+16==43) break;
        case 44: printG(texto, fuente, "de estructuras que se ajustan a la misma descripción y están", blanco,'n',45, 205+(n+43)*TTF_FontLineSkip(fuente)); if(posicion+16==44) break;
        case 45: printG(texto, fuente, "conectadas a través de filamentos que siguen patrones muy poco", blanco,'n',45, 205+(n+44)*TTF_FontLineSkip(fuente)); if(posicion+16==45) break;
        case 46: printG(texto, fuente, "regulares.", blanco,'n',45, 205+(n+45)*TTF_FontLineSkip(fuente)); if(posicion+16==46) break;
        case 47: printG(texto, fuente, "", blanco,'n',46, 205+(n+46)*TTF_FontLineSkip(fuente)); if(posicion+16==47) break;
        case 48: printG(texto, fuente, "Según la descripción anterior, el Conjunto de Mandelbrot (como", blanco,'n',47, 205+(n+47)*TTF_FontLineSkip(fuente)); if(posicion+16==48) break;
        case 49: printG(texto, fuente, "decidió llamarse a esta codificación para generar conjuntos de Julia )", blanco,'n',48, 205+(n+48)*TTF_FontLineSkip(fuente)); if(posicion+16==49) break;
        case 50: printG(texto, fuente, "parece ser un fractal; sin embargo, la ampliación de los “retoños” del", blanco,'n',49, 205+(n+49)*TTF_FontLineSkip(fuente)); if(posicion+16==50) break;
        case 51: printG(texto, fuente, "cuerpo principal genera cuerpos más “peludos y despeinados”, por lo", blanco,'n',50, 205+(n+50)*TTF_FontLineSkip(fuente)); if(posicion+16==51) break;
        case 52: printG(texto, fuente, "que no resulta completamente autosimilar. A entidades como ésta se", blanco,'n',51, 205+(n+51)*TTF_FontLineSkip(fuente)); if(posicion+16==52) break;
        case 53: printG(texto, fuente, "les sigue clasificando como fractales, pero además se les incluye", blanco,'n',52, 205+(n+52)*TTF_FontLineSkip(fuente)); if(posicion+16==53) break;
        case 54: printG(texto, fuente, "dentro de una clase particular denominada Fractales No Lineales.", blanco,'n',53, 205+(n+53)*TTF_FontLineSkip(fuente)); if(posicion+16==54) break;
      }
      break;
    case 7:
      maximo = 5;
      switch(posicion) {
        case 1: printG(texto, fuente, "M. Barnsley desarrolló una estrategia de trabajo para la generación", blanco,'n',45, 205+n*TTF_FontLineSkip(fuente)); if(posicion+16==1) break;
        case 2: printG(texto, fuente, "de fractales basada en la definición de una o más superficies con", blanco,'n',45, 205+(n+1)*TTF_FontLineSkip(fuente)); if(posicion+16==2) break;
        case 3: printG(texto, fuente, "distinta probabilidad para la realización de un conjunto de", blanco,'n',45, 205+(n+2)*TTF_FontLineSkip(fuente)); if(posicion+16==3) break;
        case 4: printG(texto, fuente, "transformaciones de afinidad que al aplicarse sobre estas superficies", blanco,'n',45, 205+(n+3)*TTF_FontLineSkip(fuente)); if(posicion+16==4) break;
        case 5: printG(texto, fuente, "dan lugar a nuevas formas que superpuestas como en un collage", blanco,'n',45, 205+(n+4)*TTF_FontLineSkip(fuente)); if(posicion+16==5) break;
        case 6: printG(texto, fuente, "reproducen una imagen que se parece a la imagen real del fractal que", blanco,'n',45, 205+(n+5)*TTF_FontLineSkip(fuente)); if(posicion+16==6) break;
        case 7: printG(texto, fuente, "se desea construir. Debido a la selección aleatoria de las", blanco,'n',45, 205+(n+6)*TTF_FontLineSkip(fuente)); if(posicion+16==7) break;
        case 8: printG(texto, fuente, "transformaciones de afinidad y el despliegue gráfico de sus órbitas", blanco,'n',45, 205+(n+7)*TTF_FontLineSkip(fuente)); if(posicion+16==8) break;
        case 9: printG(texto, fuente, "sobre las distintas superficies definidas, el método de generación de", blanco,'n',45, 205+(n+8)*TTF_FontLineSkip(fuente)); if(posicion+16==9) break;
        case 10: printG(texto, fuente, "Barnsley se puede considerar un “ping pong fractal” (Talanquer).    ", blanco,'n',45, 205+(n+9)*TTF_FontLineSkip(fuente)); if(posicion+16==10) break;
        case 11: printG(texto, fuente, "Todos los fractales que se encuentran en esta sección fueron", blanco,'n',45, 205+(n+10)*TTF_FontLineSkip(fuente)); if(posicion+16==11) break;
        case 12: printG(texto, fuente, "desarrollados “jugando ping pong fractal” con distintas", blanco,'n',45, 205+(n+11)*TTF_FontLineSkip(fuente)); if(posicion+16==12) break;
        case 13: printG(texto, fuente, "transformaciones de afinidad (encontradas en el código fuente", blanco,'n',45, 205+(n+12)*TTF_FontLineSkip(fuente)); if(posicion+16==13) break;
        case 14: printG(texto, fuente, "provisto) en forma aleatoria; lo que afirma la idea de la existencia de", blanco,'n',45, 205+(n+13)*TTF_FontLineSkip(fuente)); if(posicion+16==14) break;
        case 15: printG(texto, fuente, "distintos métodos numéricos para la construcción de fractales. ", blanco,'n',45, 205+(n+14)*TTF_FontLineSkip(fuente)); if(posicion+16==15) break;
      }
      break;
    case 8:
      maximo = 19;
      switch(posicion) {
        case 1: printG(texto, fuente, "Sobrepoblaciones", blanco,'b',45, 205+n*TTF_FontLineSkip(fuente)); if(posicion+16==1) break;
        case 2: printG(texto, fuente, "", blanco,'n',45, 205+(n+1)*TTF_FontLineSkip(fuente)); if(posicion+16==2) break;
        case 3: printG(texto, fuente, "La evolución de una población depende del ritmo de nacimientos y", blanco,'n',45, 205+(n+2)*TTF_FontLineSkip(fuente)); if(posicion+16==3) break;
        case 4: printG(texto, fuente, "muertes que se presenten dentro de la comunidad, lo que puede", blanco,'n',45, 205+(n+3)*TTF_FontLineSkip(fuente)); if(posicion+16==4) break;
        case 5: printG(texto, fuente, "traducirse en una ecuación determinista con una tasa de crecimiento", blanco,'n',45, 205+(n+4)*TTF_FontLineSkip(fuente)); if(posicion+16==5) break;
        case 6: printG(texto, fuente, "“a”. Sin embargo, la transición hacia el caos del sistema se produce", blanco,'n',45, 205+(n+5)*TTF_FontLineSkip(fuente)); if(posicion+16==6) break;
        case 7: printG(texto, fuente, "cuando se trata de predecir la población a intervalos de tiempo largos.", blanco,'n',45, 205+(n+6)*TTF_FontLineSkip(fuente)); if(posicion+16==7) break;
        case 8: printG(texto, fuente, "Variando la tasa de crecimiento “a” podrá observar que hay muchos", blanco,'n',45, 205+(n+7)*TTF_FontLineSkip(fuente)); if(posicion+16==8) break;
        case 9: printG(texto, fuente, "de sus valores para los que la población evoluciona sin seguir un", blanco,'n',45, 205+(n+8)*TTF_FontLineSkip(fuente)); if(posicion+16==9) break;
        case 10: printG(texto, fuente, "orden determinado y repleta de secciones en las que se recupera el", blanco,'n',45, 205+(n+9)*TTF_FontLineSkip(fuente)); if(posicion+16==10) break;
        case 11: printG(texto, fuente, "comportamiento periódico. Dentro de ellas se repite el mismo", blanco,'n',45, 205+(n+10)*TTF_FontLineSkip(fuente)); if(posicion+16==11) break;
        case 12: printG(texto, fuente, "esquema que en el diagrama general y así hasta el infinito; donde el", blanco,'n',45, 205+(n+11)*TTF_FontLineSkip(fuente)); if(posicion+16==12) break;
        case 13: printG(texto, fuente, "caos y el orden se entremezclan siguiendo las reglas de la geometría", blanco,'n',45, 205+(n+12)*TTF_FontLineSkip(fuente)); if(posicion+16==13) break;
        case 14: printG(texto, fuente, "fractal.", blanco,'n',45, 205+(n+13)*TTF_FontLineSkip(fuente)); if(posicion+16==14) break;
        case 15: printG(texto, fuente, "", blanco,'b',45, 205+(n+14)*TTF_FontLineSkip(fuente)); if(posicion+16==15) break;
        case 16: printG(texto, fuente, "", blanco,'b',45, 205+(n+15)*TTF_FontLineSkip(fuente)); if(posicion+16==16) break;
        case 17: printG(texto, fuente, "Bifurcaciones", blanco,'b',45, 205+(n+16)*TTF_FontLineSkip(fuente)); if(posicion+16==17) break;
        case 18: printG(texto, fuente, "", blanco,'n',45, 205+(n+17)*TTF_FontLineSkip(fuente)); if(posicion+16==18) break;
        case 19: printG(texto, fuente, "Este diagrama muestra la variación de la población en el tiempo con", blanco,'n',45, 205+(n+18)*TTF_FontLineSkip(fuente)); if(posicion+16==17) break;
        case 20: printG(texto, fuente, "el cambio de la tasa de crecimiento “a” durante el mismo. Una vez", blanco,'n',45, 205+(n+19)*TTF_FontLineSkip(fuente)); if(posicion+16==18) break;
        case 21: printG(texto, fuente, "más se puede observar que se repite el mismo esquema que en el", blanco,'n',45, 205+(n+20)*TTF_FontLineSkip(fuente)); if(posicion+16==19) break;
        case 22: printG(texto, fuente, "diagrama general de manera indefinida y a una escala menor. Este", blanco,'n',45, 205+(n+21)*TTF_FontLineSkip(fuente)); if(posicion+16==20) break;
        case 23: printG(texto, fuente, "comportamiento general de la dinámica poblacional es muy similar al", blanco,'n',45, 205+(n+22)*TTF_FontLineSkip(fuente)); if(posicion+16==21) break;
        case 24: printG(texto, fuente, "que se encuentra cuando se analizan las ecuaciones que describen", blanco,'n',45, 205+(n+23)*TTF_FontLineSkip(fuente)); if(posicion+16==22) break;
        case 25: printG(texto, fuente, "sistemas de circuitos eléctricos, reacciones oscilantes, rayos láser o", blanco,'n',45, 205+(n+24)*TTF_FontLineSkip(fuente)); if(posicion+16==23) break;
        case 26: printG(texto, fuente, "fluidos turbulentos, entre otros. La estructura de las figuras generadas", blanco,'n',45, 205+(n+25)*TTF_FontLineSkip(fuente)); if(posicion+16==24) break;
        case 27: printG(texto, fuente, "dependen de las condiciones de trabajo, pero si se identifica que su", blanco,'n',45, 205+(n+26)*TTF_FontLineSkip(fuente)); if(posicion+16==25) break;
        case 28: printG(texto, fuente, "geometría es fractal, se tiene una señal indudable de que el sistema se", blanco,'n',45, 205+(n+27)*TTF_FontLineSkip(fuente)); if(posicion+16==26) break;
        case 29: printG(texto, fuente, "comporta caóticamente.", blanco,'n',45, 205+(n+28)*TTF_FontLineSkip(fuente)); if(posicion+16==29) break;
      }
      break;
    case 9:
      maximo = 4;
      switch(posicion) {
        case 1: printG(texto, fuente, "Los autómatas celulares fueron empleados por primera vez por los", blanco,'n',45, 205+n*TTF_FontLineSkip(fuente)); if(posicion+16==1) break;
        case 2: printG(texto, fuente, "matemáticos John von Neumann y Stanislaw Ulam en 1948 con el", blanco,'n',45, 205+(n+1)*TTF_FontLineSkip(fuente)); if(posicion+16==2) break;
        case 3: printG(texto, fuente, "propósito de simular la reproducción en algunos sistemas biológicos.", blanco,'n',45, 205+(n+2)*TTF_FontLineSkip(fuente)); if(posicion+16==3) break;
        case 4: printG(texto, fuente, "Para construirlos basta tomar un arreglo de celdas y otorgar a cada", blanco,'n',45, 205+(n+3)*TTF_FontLineSkip(fuente)); if(posicion+16==4) break;
        case 5: printG(texto, fuente, "una un valor que identifique el estado que caracteriza a dicho espacio", blanco,'n',45, 205+(n+4)*TTF_FontLineSkip(fuente)); if(posicion+16==5) break;
        case 6: printG(texto, fuente, "reservado para un individuo dentro de la población (vivo o muerto).", blanco,'n',45, 205+(n+5)*TTF_FontLineSkip(fuente)); if(posicion+16==6) break;
        case 7: printG(texto, fuente, "Una vez definido el estado inicial para todo el sistema, se procede a", blanco,'n',45, 205+(n+6)*TTF_FontLineSkip(fuente)); if(posicion+16==7) break;
        case 8: printG(texto, fuente, "estudiar su evolución mediante la aplicación de una regla de", blanco,'n',45, 205+(n+7)*TTF_FontLineSkip(fuente)); if(posicion+16==8) break;
        case 9: printG(texto, fuente, "crecimiento previamente establecida sobre la que comienzan a", blanco,'n',45, 205+(n+8)*TTF_FontLineSkip(fuente)); if(posicion+16==9) break;
        case 10: printG(texto, fuente, "elaborarse las iteraciones. La presencia de la geometría fractal en el", blanco,'n',45, 205+(n+9)*TTF_FontLineSkip(fuente)); if(posicion+16==10) break;
        case 11: printG(texto, fuente, "proceso se hace evidente en nuestros diagramas; al igual que en la", blanco,'n',45, 205+(n+10)*TTF_FontLineSkip(fuente)); if(posicion+16==11) break;
        case 12: printG(texto, fuente, "simulación de ondas químicas, el flujo de fluidos a través de obstáculos", blanco,'n',45, 205+(n+11)*TTF_FontLineSkip(fuente)); if(posicion+16==12) break;
        case 13: printG(texto, fuente, "o el crecimiento de copos de nieve adaptados para ser asistidas", blanco,'n',45, 205+(n+12)*TTF_FontLineSkip(fuente)); if(posicion+16==13) break;
        case 14: printG(texto, fuente, "mediante autómatas celulares.", blanco,'n',45, 205+(n+13)*TTF_FontLineSkip(fuente)); if(posicion+16==14) break;
      }
      break;
    case 10:    //Mandelbrot^3, Mandelbrot^4, Mandelbrot^5
      maximo = 10;
      switch(posicion) {
        case 1: printG(texto, fuente, "Estos nuevos fractales (Mandelbrot^n), son escencialmente iguales al", blanco,'n',45, 205+n*TTF_FontLineSkip(fuente)); if(posicion+16==1) break;
        case 2: printG(texto, fuente, "fractal de Mandelbrot normal. Difieren de éste en la fórmula iterativa", blanco,'n',45, 205+(n+1)*TTF_FontLineSkip(fuente)); if(posicion+16==2) break;
        case 3: printG(texto, fuente, "que genera al fractal.", blanco,'n',45, 205+(n+2)*TTF_FontLineSkip(fuente)); if(posicion+16==3) break;
        case 4: printG(texto, fuente, "", blanco,'n',45, 205+(n+3)*TTF_FontLineSkip(fuente)); if(posicion+16==4) break;
        case 5: printG(texto, fuente, "Recordando la fórmula del conjunto de Mandelbrot tradicional, tenemos:", blanco,'n',45, 205+(n+4)*TTF_FontLineSkip(fuente)); if(posicion+16==5) break;
        case 6: printG(texto, fuente, "", blanco,'n',45, 205+(n+5)*TTF_FontLineSkip(fuente)); if(posicion+16==6) break;
        case 7: printG(texto, fuente, "        Z_(n+1) = Z_n^2 + c", blanco,'n',45, 205+(n+6)*TTF_FontLineSkip(fuente)); if(posicion+16==7) break;
        case 8: printG(texto, fuente, "", blanco,'n',45, 205+(n+7)*TTF_FontLineSkip(fuente)); if(posicion+16==8) break;
        case 9: printG(texto, fuente, "Pero si ahora no elevamos al número complejo Z_n al cuadrado, sino que", blanco,'n',45, 205+(n+8)*TTF_FontLineSkip(fuente)); if(posicion+16==9) break;
        case 10: printG(texto, fuente, "elegimos otra potencia, tendremos un nuevo fractal. Por ejemplo si", blanco,'n',45, 205+(n+9)*TTF_FontLineSkip(fuente)); if(posicion+16==10) break;
        case 11: printG(texto, fuente, "elevamos al cubo, tenemos la fórmula recursiva:", blanco,'n',45, 205+(n+10)*TTF_FontLineSkip(fuente)); if(posicion+16==11) break;
        case 12: printG(texto, fuente, "", blanco,'n',45, 205+(n+11)*TTF_FontLineSkip(fuente)); if(posicion+16==12) break;
        case 13: printG(texto, fuente, "        Z_(n+1) = Z_n^3 + c", blanco,'n',45, 205+(n+12)*TTF_FontLineSkip(fuente)); if(posicion+16==13) break;
        case 14: printG(texto, fuente, "", blanco,'n',45, 205+(n+13)*TTF_FontLineSkip(fuente)); if(posicion+16==14) break;
        case 15: printG(texto, fuente, "A los puntos que convergen a algún valor al aplicar la fórmula iterativa", blanco,'n',45, 205+(n+14)*TTF_FontLineSkip(fuente)); if(posicion+16==15) break;
        case 16: printG(texto, fuente, "anterior, conforman el conjunto de Mandelbrot^3. De igual forma se", blanco,'n',45, 205+(n+15)*TTF_FontLineSkip(fuente)); if(posicion+16==16) break;
        case 17: printG(texto, fuente, " obtienen Mandelbrot^4 y Mandelbrot^5:", blanco,'n',45, 205+(n+16)*TTF_FontLineSkip(fuente)); if(posicion+16==17) break;
        case 18: printG(texto, fuente, "", blanco,'n',45, 205+(n+17)*TTF_FontLineSkip(fuente)); if(posicion+16==18) break;
        case 19: printG(texto, fuente, "        Z_(n+1) = Z_n^4 + c    Mandelbrot^4", blanco,'n',45, 205+(n+18)*TTF_FontLineSkip(fuente)); if(posicion+16==19) break;
        case 20: printG(texto, fuente, "        Z_(n+1) = Z_n^3 + c    Mandelbrot^5", blanco,'n',45, 205+(n+19)*TTF_FontLineSkip(fuente)); if(posicion+16==18) break;

      }
      break;
    case 11:    //Fractal de Newton-Raphson
      maximo = 11;
      switch(posicion) {
        case 1: printG(texto, fuente, "Este fractal se genera al utilizar el método para encontrar raíces", blanco,'n',45, 205+n*TTF_FontLineSkip(fuente)); if(posicion+16==1) break;
        case 2: printG(texto, fuente, "denominado Newton-Raphson. El algoritmo es el que sigue: se selecciona", blanco,'n',45, 205+(n+1)*TTF_FontLineSkip(fuente)); if(posicion+16==2) break;
        case 3: printG(texto, fuente, "un punto del plano complejo y se utiliza como una primera aproximación", blanco,'n',45, 205+(n+2)*TTF_FontLineSkip(fuente)); if(posicion+16==3) break;
        case 4: printG(texto, fuente, "de la raíz. Posteriormente se emplea iterativamente la fórmula de", blanco,'n',45, 205+(n+3)*TTF_FontLineSkip(fuente)); if(posicion+16==4) break;
        case 5: printG(texto, fuente, "Newton-Raphson:", blanco,'n',45, 205+(n+4)*TTF_FontLineSkip(fuente)); if(posicion+16==5) break;
        case 6: printG(texto, fuente, "     x_(i+1) = x_i – f(x_i)/f'(x_i)", blanco,'n',45, 205+(n+5)*TTF_FontLineSkip(fuente)); if(posicion+16==6) break;
        case 7: printG(texto, fuente, "", blanco,'n',45, 205+(n+6)*TTF_FontLineSkip(fuente)); if(posicion+16==7) break;
        case 8: printG(texto, fuente, "Dependiendo de la raíz a la que se converja, es el color que se selecciona,", blanco,'n',45, 205+(n+7)*TTF_FontLineSkip(fuente)); if(posicion+16==8) break;
        case 9: printG(texto, fuente, "variando la intensidad dependiendo del número de iteraciones que se hayan", blanco,'n',45, 205+(n+8)*TTF_FontLineSkip(fuente)); if(posicion+16==9) break;
        case 10: printG(texto, fuente, "necesitado para llegar a la raíz. El resultado final es una estructura", blanco,'n',45, 205+(n+9)*TTF_FontLineSkip(fuente)); if(posicion+16==10) break;
        case 11: printG(texto, fuente, "fractal autosimilar a cualquier escala. El polinomio que se empleó para", blanco,'n',45, 205+(n+10)*TTF_FontLineSkip(fuente)); if(posicion+16==11) break;
        case 12: printG(texto, fuente, "buscar sus raíces fue:", blanco,'n',45, 205+(n+11)*TTF_FontLineSkip(fuente)); if(posicion+16==12) break;
        case 13: printG(texto, fuente, "", blanco,'n',45, 205+(n+12)*TTF_FontLineSkip(fuente)); if(posicion+16==13) break;
        case 14: printG(texto, fuente, "     f(z) = x^3 – 1 = 0", blanco,'n',45, 205+(n+13)*TTF_FontLineSkip(fuente)); if(posicion+16==14) break;
        case 15: printG(texto, fuente, "", blanco,'n',45, 205+(n+14)*TTF_FontLineSkip(fuente)); if(posicion+16==15) break;
        case 16: printG(texto, fuente, "Como f(z) tiene tres raíces, el plano complejo se divide en tres regiones.", blanco,'n',45, 205+(n+15)*TTF_FontLineSkip(fuente)); if(posicion+16==16) break;
        case 17: printG(texto, fuente, "Cada punto de una cierta región converge a una raíz determinada. Además,", blanco,'n',45, 205+(n+16)*TTF_FontLineSkip(fuente)); if(posicion+16==17) break;
        case 18: printG(texto, fuente, "se observa que a su vez existen regiones más pequeñas en las que también", blanco,'n',45, 205+(n+17)*TTF_FontLineSkip(fuente)); if(posicion+16==18) break;
        case 19: printG(texto, fuente, "se puede llegar a cualquiera de las tres raíces. El método de Newton-", blanco,'n',45, 205+(n+18)*TTF_FontLineSkip(fuente)); if(posicion+16==19) break;
        case 20: printG(texto, fuente, "Raphson presenta entonces un comportamiento fractal en cuanto a la raíz", blanco,'n',45, 205+(n+19)*TTF_FontLineSkip(fuente)); if(posicion+16==20) break;
        case 21: printG(texto, fuente, "a la que convergerá un punto dado.", blanco,'n',45, 205+(n+20)*TTF_FontLineSkip(fuente)); if(posicion+16==21) break;
      }
      break;
  }

  /*Slock(screen);
  for (x = 40; x < 760; x ++)
    for (y = 561; y <= 600; y ++)
      if(x <= 20 || y <= 20 || x >= 780 || y >= 580) DrawPixel(screen, x, y, 65, 198, 49);
      else DrawPixel(screen, x, y, 197, 129, 49);
  Sulock(screen);*/
  ActIMG(fondo, 40, 561, 720, 39, 40, 561);

  SDL_Flip(screen);
  return maximo;
}
