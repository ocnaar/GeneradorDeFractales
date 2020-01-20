/***************************************************************************
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_draw.h>
#include "aleph.h"
#include "acciones.h"

extern num_iter;

int main(int argc, char *argv[])
{
  int fractal = 1, opcion, hecho = 0, bandera_fract=0;

  resX = 800;        //Definicion de la resolución. Si se cambia aqui, cambia en todo el programa.
  resY = 600;
  paleta_color = 0;
  pantallaC = 0;

  inicializacion(); //Inicializa el sistema SDL
  intro();          //Crea la pantalla de introduccion.
  fondo = IMG_Load("imagenes/fondo.png");
  //El siguiente while controla la eleccion a traves de los diferentes menues. Llama al menu correspondiente,
  //el cual le regresa un valor dependiendo del elemento seleccionado, y dependiendo de este valor se decide
  //que hacer.
  while(hecho == 0)
  {
    opcion = menu();
    switch(opcion)
    {
      case 1:    //Se eligio generar fractales
        while (opcion != 13)
        {
          if (bandera_fract == 0) opcion = menuFract();
          if (bandera_fract == 1) opcion = menuFract_adicional();
          if (opcion == 14) bandera_fract = 1;
	  if (opcion == 15) bandera_fract = 0;
          if (opcion == 1) fractales(screen, 1, 1);
          if (opcion == 2 || opcion == 3 || opcion == 4) fractales2(screen, opcion+2);
          if (opcion >4 && opcion <= 11) pantallaTexto(opcion + 1);
          if (opcion >= 21) fractales(screen, 1, opcion-19);
        }
        break;
      case 2:    //Se eligio marco teorico.
        while (opcion != 4)
        {
          opcion = menuMarcoT();
          if(opcion == 1) pantallaTexto(1);
          if(opcion == 2) pantallaTexto(2);
          if(opcion == 3) pantallaTexto(3);
        }
        break;
      case 3:    //Se eligieron creditos.
        pantallaTexto(4);
        break;
      case 4:    //Se eligio Opciones
        opcion = 6;
        while (opcion == 6)
        {
          opcion = opciones();
          if (opcion == 6) {
            if (pantallaC == 1) screen=SDL_SetVideoMode(resX,resY,32,SDL_HWSURFACE|SDL_FULLSCREEN);
            else screen=SDL_SetVideoMode(resX,resY,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
          }
        }
        break;
      case 5:    //Se eligio ayuda.
        pantallaTexto(5);
        break;
      case 6:    //Se eligio Salir.
        hecho = 1;
        break;
    }
  }
  return 0;
}

void intro()
{
  int hecho = 0, x, y;
  SDL_Surface *logos, *titulo;
  SDL_Event evento;

  /*Slock(screen);  //Bloquea la pantalla
  for (x = 0; x < resX; x ++)
    for (y = 0; y < resY; y ++)
      DrawPixel(screen, x, y, 82, 125, 164);
  Sulock(screen);  //Desbloquea la pantalla*/
  fondo = IMG_Load("imagenes/intro/fondointro.png");
  logos = IMG_Load("imagenes/intro/logos.png");
  titulo = IMG_Load("imagenes/intro/titulointro.png");


  DibujaIMG(fondo, 0, 0);
  DibujaIMG(titulo, 400-titulo->w/2, 100);
  DibujaIMG(logos, 800-logos->w, 0);
  
  fuente=TTF_OpenFont("fuentes/vera.ttf", 22);
  printG(texto, fuente, "Generador de Fractales.",blanco, 'b', -1, 290);

  fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
  printG(texto, fuente, "Versión 1.1",blanco, 'i', -1, 290+2*TTF_FontLineSkip(fuente));
  printG(texto, fuente, "Junio de 2005",blanco, 'i', -1, 290+3*TTF_FontLineSkip(fuente));
  printG(texto, fuente, "Presione cualquier tecla para continuar.",blanco, 'b', -1, 450);
  fuente=TTF_OpenFont("fuentes/vera.ttf", 10);
  printG(texto, fuente, "Este programa es Software Libre. Se permite su redistribución, y/o modificación bajo los",
         blanco, 'n', -1, resY - 6*TTF_FontLineSkip(fuente));
  printG(texto, fuente, "términos de la GNU General Public Licence, tal como la publica la Free Software Fundation;",
         blanco,'n',-1, resY - 5*TTF_FontLineSkip(fuente));
  printG(texto, fuente, "ya sea la versión 2 de la Licencia, o (a su elección) cualquier versión más nueva.",
         blanco,'n',-1, resY - 4*TTF_FontLineSkip(fuente));
  printG(texto, fuente, "Seleccione Créditos en el menú para más información.",
         blanco, 'n', -1, resY - 3*TTF_FontLineSkip(fuente));
  printG(texto, fuente, "Copyright (c) 2004, 2005, Barousse Miguel, Narváez Octavio.",
         blanco, 'n', -1, resY - 2*TTF_FontLineSkip(fuente));

  SDL_Flip(screen);  //Actualiza la pantalla
  while(hecho == 0)
  {
    SDL_WaitEvent(&evento);
      if (evento.type == SDL_KEYDOWN || evento.type == SDL_QUIT) hecho = 1;
  }

  //Eliminar las capas utilizadas:
  SDL_FreeSurface(logos);
  SDL_FreeSurface(titulo);
}


int menu()
{
  int hecho = 0, x, y, mouseX, mouseY, elemento=0, elemento_res=0;
  SDL_Surface *titulo, *info_marco;
  SDL_Event evento;

  info_marco = IMG_Load("imagenes/menu/marco.png");
  titulo = IMG_Load("imagenes/intro/titulo.png");


  /*// Colorea la pantalla
  Slock(screen);  
  for (x = 0; x < resX; x ++)
    for (y = 0; y < resY; y ++)
      if(x <= 20 || y <= 20 || x >= resX-20 || y >= resY-20) DrawPixel(screen, x, y, 65, 198, 49);
      else DrawPixel(screen, x, y, 197, 129, 49);
  Sulock(screen);*/
  DibujaIMG(fondo, 0, 0);
  
  //Crea las entradas del menu, y coloca iconos:
  DibujaIMG(titulo, resX/2-titulo->w/2, 50);
  DibujaIMG(info_marco, 450, resY/2 -100);
  icon_menu_princ(screen, resX, resY);
  entradas_principal(resX, resY, 0, screen);
  SDL_Flip(screen);
  
  //Decide que hacer si ocurre un evento
  while(hecho == 0)
  {
    SDL_WaitEvent(&evento);
    {
      switch(evento.type)
      {
        case SDL_QUIT:
          elemento = 6;
          hecho = 1;
          break;
        case SDL_KEYDOWN:
          if ( evento.key.keysym.sym == SDLK_ESCAPE )
          {
            elemento = 6;
            hecho = 1;
          }
          if ( evento.key.keysym.sym == SDLK_i )
          {
            intro();
            fondo = IMG_Load("imagenes/fondo.png");
            elemento = 7;
            hecho = 1;
          }
          break;
        case SDL_MOUSEMOTION: case SDL_MOUSEBUTTONDOWN:
          SDL_GetMouseState(&mouseX, &mouseY);
          //Define que elemento del menu se selecciona
          if(mouseX >= 150 && mouseX <= 415) {
            if (mouseY >= 192 && mouseY <= 224) elemento = 1;
              else { if (mouseY >= 240 && mouseY <= 272) elemento = 2;
                else { if(mouseY >= 288 && mouseY <= 320) elemento = 3;
                  else { if(mouseY >= 336 && mouseY <= 368) elemento = 4;
                    else { if(mouseY >= 384 && mouseY <= 416) elemento = 5;
                      else { if(mouseY >= 432 && mouseY <= 464) elemento = 6;
                        else elemento = 0;
                    }
                  }
                }
              }
            }
          } else elemento = 0;
          if (elemento != elemento_res)
          {
            elemento_res = elemento;
            DibujaIMG(info_marco, 450, resY/2 -100);
            entradas_principal(resX, resY, elemento, screen);
            SDL_Flip(screen);
          } else {
            if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1)) if (elemento != 0) hecho = 1;
          }
          break;
      }
    }
  }

  SDL_FreeSurface(titulo);
  SDL_FreeSurface(info_marco);
  
  return elemento;
}

int menuFract()
{
  int hecho = 0, x, y, mouseX, mouseY, elemento=0, elemento_res=0;
  SDL_Surface *titulo, *info_marco;
  SDL_Event evento;
  
  info_marco = IMG_Load("imagenes/menu/marco.png");
  titulo = IMG_Load("imagenes/intro/titulo.png");
  
  // Colorea la pantalla
  /*Slock(screen);  
  for (x = 0; x < resX; x ++)
    for (y = 0; y < resY; y ++)
      if(x <= 20 || y <= 20 || x >= resX-20 || y >= resY-20) DrawPixel(screen, x, y, 65, 198, 49);
      else DrawPixel(screen, x, y, 197, 129, 49);
  Sulock(screen);*/
  DibujaIMG(fondo, 0, 0);

  //Crea las entradas del menu, y coloca iconos:
  DibujaIMG(titulo, resX/2-titulo->w/2, 50);
  DibujaIMG(info_marco, 450, resY/2 -100);
  icon_fractal(screen, resX, resY);
  
  entradas_fractal(resX, resY, 0, screen);
  SDL_Flip(screen);
  
  //Decide que hacer si ocurre un evento
  while(hecho == 0)
  {
    SDL_WaitEvent(&evento);
    {
      switch(evento.type)
      {
        case SDL_QUIT:
          hecho = 1;
          elemento = 13;
          break;
        case SDL_KEYDOWN:
          if ( evento.key.keysym.sym == SDLK_ESCAPE )
          {
            hecho = 1;
            elemento = 13;
          }
          break;
        case SDL_MOUSEMOTION: case SDL_MOUSEBUTTONDOWN:
          SDL_GetMouseState(&mouseX, &mouseY);
          //Define que elemento del menu se selecciona
          if((mouseX > 182 && mouseX <= 450) && (mouseY >= 192 && mouseY <= 272)) elemento = 1;
            else { if((mouseX > 182 && mouseX <= 450) && (mouseY >= 288 && mouseY <= 416)) elemento = 2;
              else { if((mouseX > 182 && mouseX <= 450) && (mouseY >= 432 && mouseY <= 512)) elemento = 3;
                else { if((mouseX > 182 && mouseX <= 450) && (mouseY >= 528 && mouseY <= 560)) elemento = 4;
                  else { if((mouseX >= 150 && mouseX <= 182) && (mouseY >= 187 && mouseY <= 219)) elemento = 5;
                    else { if((mouseX >= 150 && mouseX <= 182) && (mouseY >= 283 && mouseY <= 315)) elemento = 6;
                      else { if((mouseX >= 150 && mouseX <= 182) && (mouseY >= 427 && mouseY <= 459)) elemento = 7;
                        else { if((mouseX >= 150 && mouseX <= 182) && (mouseY >= 523 && mouseY <= 555)) elemento = 8;
                          else { if((mouseX >= 738 && mouseX <= 770) && (mouseY >= 524 && mouseY <= 556)) elemento = 13;
                            else { if((mouseX >= 182 && mouseX <= 450) && (mouseY >= 576 && mouseY <= 600)) elemento = 14;
                              else elemento = 0;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          if (elemento != elemento_res)
          {
            elemento_res = elemento;
            DibujaIMG(info_marco, 450, resY/2 -100);
            if (elemento <= 4 || elemento >= 13) entradas_fractal(resX, resY, elemento, screen);
            else entradas_fractal(resX, resY, 0, screen);
            SDL_Flip(screen);
          } else {
            if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1)) if (elemento != 0) hecho = 1;
          }
          break;
      }
    }
  }

  SDL_FreeSurface(titulo);
  SDL_FreeSurface(info_marco);

  return elemento;
}

int menuFract_adicional()
{
  int hecho = 0, x, y, mouseX, mouseY, elemento=0, elemento_res=0;
  SDL_Surface *titulo, *info_marco;
  SDL_Event evento;
  
  info_marco = IMG_Load("imagenes/menu/marco.png");
  titulo = IMG_Load("imagenes/intro/titulo.png");
  
  // Colorea la pantalla
  /*Slock(screen);  
  for (x = 0; x < resX; x ++)
    for (y = 0; y < resY; y ++)
      if(x <= 20 || y <= 20 || x >= resX-20 || y >= resY-20) DrawPixel(screen, x, y, 65, 198, 49);
      else DrawPixel(screen, x, y, 197, 129, 49);
  Sulock(screen);*/
  DibujaIMG(fondo, 0, 0);

  //Crea las entradas del menu, y coloca iconos:
  DibujaIMG(titulo, resX/2-titulo->w/2, 50);
  DibujaIMG(info_marco, 450, resY/2 -100);
  icon_fractal_adicional(screen, resX, resY);
  
  entradas_fractal_adicional(resX, resY, 0, screen);
  SDL_Flip(screen);
  
  //Decide que hacer si ocurre un evento
  while(hecho == 0)
  {
    SDL_WaitEvent(&evento);
    {
      switch(evento.type)
      {
        case SDL_QUIT:
          hecho = 1;
          elemento = 13;
          break;
        case SDL_KEYDOWN:
          if ( evento.key.keysym.sym == SDLK_ESCAPE )
          {
            hecho = 1;
            elemento = 13;
          }
          break;
        case SDL_MOUSEMOTION: case SDL_MOUSEBUTTONDOWN:
          SDL_GetMouseState(&mouseX, &mouseY);
          //Define que elemento del menu se selecciona
          if((mouseX > 182 && mouseX <= 450) && (mouseY >= 192 && mouseY <= 224)) elemento = 21;
            else { if((mouseX > 182 && mouseX <= 450) && (mouseY >= 240 && mouseY <= 272)) elemento = 22;
              else { if((mouseX > 182 && mouseX <= 450) && (mouseY >= 288 && mouseY <= 320)) elemento = 23;
                else { if((mouseX > 182 && mouseX <= 450) && (mouseY >= 336 && mouseY <= 368)) elemento = 24;
                  else { if((mouseX >= 150 && mouseX <= 182) && (mouseY >= 187 && mouseY <= 313)) elemento = 9;
                    else { if((mouseX >= 150 && mouseX <= 182) && (mouseY >= 329 && mouseY <= 361)) elemento = 10;
                      else { if((mouseX >= 738 && mouseX <= 770) && (mouseY >= 524 && mouseY <= 556)) elemento = 13;
                        else { if((mouseX >= 182 && mouseX <= 450) && (mouseY >= 576 && mouseY <= 600)) elemento = 15;
                          else elemento = 0;
                        }
                      }
                    }
                  }
                }
              }
            }
          if (elemento != elemento_res)
          {
            elemento_res = elemento;
            DibujaIMG(info_marco, 450, resY/2 -100);
            if (elemento >= 13) entradas_fractal_adicional(resX, resY, elemento, screen);
            else entradas_fractal_adicional(resX, resY, 0, screen);
            SDL_Flip(screen);
          } else {
            if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1)) if (elemento != 0) hecho = 1;
          }
          break;
      }
    }
  }

  SDL_FreeSurface(titulo);
  SDL_FreeSurface(info_marco);

  return elemento;
}

int menuMarcoT()
{
  int hecho = 0, x, y, mouseX, mouseY, elemento=0, elemento_res=0;
  SDL_Surface *titulo, *info_marco;
  SDL_Event evento;
  
  info_marco = IMG_Load("imagenes/menu/marco.png");
  titulo = IMG_Load("imagenes/intro/titulo.png");
  
  // Colorea la pantalla
  /*Slock(screen);  
  for (x = 0; x < resX; x ++)
    for (y = 0; y < resY; y ++)
      if(x <= 20 || y <= 20 || x >= resX-20 || y >= resY-20) DrawPixel(screen, x, y, 65, 198, 49);
      else DrawPixel(screen, x, y, 197, 129, 49);
  Sulock(screen);*/
  DibujaIMG(fondo, 0, 0);
  
  //Crea las entradas del menu, y coloca iconos:
  DibujaIMG(titulo, resX/2-titulo->w/2, 50);
  DibujaIMG(info_marco, 450, resY/2 -100);
  icon_marcoT(screen, resX, resY);
  
  entradas_marcoT(resX, resY, 0, screen);
  SDL_Flip(screen);
  
  //Decide que hacer si ocurre un evento
  while(hecho == 0)
  {
    SDL_WaitEvent(&evento);
    {
      switch(evento.type)
      {
        case SDL_QUIT:
          hecho = 1;
          elemento = 4;
          break;
        case SDL_KEYDOWN:
          if ( evento.key.keysym.sym == SDLK_ESCAPE )
          {
            hecho = 1;
            elemento = 4;
          }
          break;
        case SDL_MOUSEMOTION: case SDL_MOUSEBUTTONDOWN:
          SDL_GetMouseState(&mouseX, &mouseY);
          //Define que elemento del menu se selecciona
          if((mouseX >= 150 && mouseX <= 450) && (mouseY >= 192 && mouseY <= 224)) elemento = 1;
            else { if((mouseX >= 150 && mouseX <= 450) && (mouseY >= 240 && mouseY <= 272)) elemento = 2;
              else { if((mouseX >= 150 && mouseX <= 450) && (mouseY >= 288 && mouseY <= 368)) elemento = 3;
                else { if((mouseX >= 738 && mouseX <= 770) && (mouseY >= 524 && mouseY <= 556)) elemento = 4;
                  else elemento = 0;
                }
              }
            }
          if (elemento != elemento_res)
          {
            elemento_res = elemento;
            DibujaIMG(info_marco, 450, resY/2 -100);
            entradas_marcoT(resX, resY, elemento, screen);
            SDL_Flip(screen);
          } else {
            if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1)) if (elemento != 0) hecho = 1;
          }
          break;
      }
    }
  }

  SDL_FreeSurface(titulo);
  SDL_FreeSurface(info_marco);

  return elemento;
}


int opciones()
{
  int hecho = 0, x, y, mouseX, mouseY, elemento=0, elemento_res=0, desp;
  SDL_Surface *titulo, *ico_atras, *paleta;
  SDL_Event evento;
  
  titulo = IMG_Load("imagenes/intro/titulo.png");
  ico_atras = IMG_Load("imagenes/iconos/atras.png");
  
  // Colorea la pantalla
  /*Slock(screen);  
  for (x = 0; x < resX; x ++)
    for (y = 0; y < resY; y ++)
      if(x <= 20 || y <= 20 || x >= resX-20 || y >= resY-20) DrawPixel(screen, x, y, 65, 198, 49);
      else DrawPixel(screen, x, y, 197, 129, 49);
  Sulock(screen);*/
  DibujaIMG(fondo, 0, 0);
  
  //Crea las entradas del menu, y coloca iconos:
  DibujaIMG(titulo, resX/2-titulo->w/2, 50);
  DibujaIMG(ico_atras, 738, resY/2 + 224);
  desp = entradas_opciones(resX, resY, 0, screen);
  icon_opciones(desp);
  
  paleta = IMG_Load("imagenes/opciones/paleta1.png");
  DibujaIMG(paleta, 400, 188 + 3*desp);
  paleta = IMG_Load("imagenes/opciones/paleta2.png");
  DibujaIMG(paleta, 400, 188 + 4*desp);
  paleta = IMG_Load("imagenes/opciones/paleta3.png");
  DibujaIMG(paleta, 400, 188 + 5*desp);
  paleta = IMG_Load("imagenes/opciones/paleta4.png");
  DibujaIMG(paleta, 400, 188 + 6*desp);
  paleta = IMG_Load("imagenes/opciones/paleta5.png");
  DibujaIMG(paleta, 400, 188 + 7*desp);
  
  SDL_Flip(screen);
  
  //Decide que hacer si ocurre un evento
  while(hecho == 0)
  {
    SDL_WaitEvent(&evento);
    {
      switch(evento.type)
      {
        case SDL_QUIT:
          hecho = 1;
          elemento = 5;
          break;
        case SDL_KEYDOWN:
          if ( evento.key.keysym.sym == SDLK_ESCAPE )
          {
            hecho = 1;
            elemento = 5;
          }
          break;
        case SDL_MOUSEBUTTONDOWN:
          SDL_GetMouseState(&mouseX, &mouseY);
          //Define que elemento del menu se selecciona
          if((mouseX >= 170 && mouseX <= 188) && (mouseY >= 188 + 3*desp && mouseY <= 203 + 3*desp)) elemento = 0;
            else { if((mouseX >= 170 && mouseX <= 188) && (mouseY >= 188 + 4*desp && mouseY <= 203 + 4*desp)) elemento = 1;
              else { if((mouseX >= 170 && mouseX <= 188) && (mouseY >= 188 + 5*desp && mouseY <= 203 + 5*desp)) elemento = 2;
                else { if((mouseX >= 170 && mouseX <= 188) && (mouseY >= 188 + 6*desp && mouseY <= 203 + 6*desp)) elemento = 3;
                  else { if((mouseX >= 170 && mouseX <= 188) && (mouseY >= 188 + 7*desp && mouseY <= 203 + 7*desp)) elemento = 4;
                    else { if((mouseX >= 738 && mouseX <= 770) && (mouseY >= 524 && mouseY <= 556)) elemento = 5;
                      else { if((mouseX >= 170 && mouseX <= 188) && (mouseY >= 188 + 11*desp && mouseY <= 203 + 11*desp)) elemento = 6;
                        else elemento = 7;
                      }
                    }
                  }
                }
              }
            }
          if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1))
            if (elemento < 5)
            {
              paleta_color = elemento;
              icon_opciones(desp);
              SDL_Flip(screen);
            } else {
              if (elemento == 5) hecho = 1;
              if (elemento == 6) {
                hecho = 1;
                if (pantallaC == 0) pantallaC = 1;
                else pantallaC = 0;
              }
            }
      }
    }
  }

  SDL_FreeSurface(titulo);
  SDL_FreeSurface(ico_atras);
  SDL_FreeSurface(paleta);
  return elemento;
}


void pantallaTexto(int seleccion)
{
  int hecho = 0, x, y, mouseX, mouseY, elemento=0, posicion = 1, maximo;
  float p, m;
  SDL_Surface *titulo, *barra, *atras, *cuadro;
  SDL_Event evento;
  
  titulo = IMG_Load("imagenes/intro/titulo.png");
  barra = IMG_Load("imagenes/menu/barra.png");
  cuadro = IMG_Load("imagenes/menu/deslizador.png");
  atras = IMG_Load("imagenes/iconos/atras.png");
  
  // Colorea la pantalla
  /*Slock(screen);  
  for (x = 0; x < resX; x ++)
    for (y = 0; y < resY; y ++)
      if(x <= 20 || y <= 20 || x >= resX-20 || y >= resY-20) DrawPixel(screen, x, y, 65, 198, 49);
      else DrawPixel(screen, x, y, 197, 129, 49);
  Sulock(screen);*/
  DibujaIMG(fondo, 0, 0);
  
  //Crea el texto inicial, y las imagenes:
  escribe_titulo(seleccion);
  DibujaIMG(atras, 728, 166);
  DibujaIMG(titulo, resX/2-titulo->w/2, 50);
  DibujaIMG(barra, 746, 200);
  maximo = inserta_texto(seleccion, posicion, screen);
  DibujaIMG(cuadro, 746, 216);
  
  SDL_Flip(screen);
  
  //Decide que hacer si ocurre un evento
  while(hecho == 0)
  {
    SDL_WaitEvent(&evento);
    {
      switch(evento.type)
      {
        case SDL_QUIT:
          hecho = 1;
          break;
        case SDL_KEYDOWN:
          if ( evento.key.keysym.sym == SDLK_ESCAPE ) hecho = 1;
          if (evento.key.keysym.sym == SDLK_UP) posicion --;
          if (evento.key.keysym.sym == SDLK_DOWN) posicion ++;
          if (evento.key.keysym.sym == SDLK_PAGEUP) posicion -= 10;
          if (evento.key.keysym.sym == SDLK_PAGEDOWN) posicion += 10;
          if (posicion < 1) posicion = 1;
          if (posicion > maximo) posicion = maximo;
          DibujaIMG(barra, 746, 200);
          p = posicion-1; m = maximo-1;
          DibujaIMG(cuadro, 746, 216.0+310.0*(p/m));
          inserta_texto(seleccion, posicion, screen);
          break;
        case SDL_MOUSEBUTTONDOWN:
          SDL_GetMouseState(&mouseX, &mouseY);
          //Define que elemento del menu se selecciona
          if((mouseX >= 744 && mouseX <= 760) && (mouseY >= 200 && mouseY <= 216)) elemento = 1;
            else { if((mouseX >= 744 && mouseX <= 760) && (mouseY >= 545 && mouseY <= 561)) elemento = 2;
              else { if((mouseX >= 728 && mouseX <= 760) && (mouseY >= 166 && mouseY <= 198)) elemento = 3;
                else elemento = 0;
              }
            }
          if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1)) if (elemento != 0)
          {
            if (elemento == 3) hecho = 1;
            else
            {
              if (elemento == 1) if (posicion != 1) posicion --;
              if (elemento == 2) if (posicion != maximo) posicion ++;
              DibujaIMG(barra, 746, 200);
              p = posicion-1; m = maximo-1;
              DibujaIMG(cuadro, 746, 216.0+310.0*(p/m));
              inserta_texto(seleccion, posicion, screen);
              SDL_Flip(screen);
            }
          }
          break;
      }
    }
  }

  SDL_FreeSurface(titulo);
  SDL_FreeSurface(barra);
  SDL_FreeSurface(cuadro);
  SDL_FreeSurface(atras);
}


void fractales(SDL_Surface *screen, int fractal, int formula)
{
  int x, y, fin = 0, accion=-1;
  double despX=0, despY=0, op1 = 0, op2 = 0, factor=0.9, escala = 0.005, a=0, b=0, c=0.005;
  SDL_Surface *navegacion;
  SDL_Event evento;
  
  navegacion = IMG_Load("imagenes/iconos/navegacion.png");
  DibujaIMG(navegacion, resX - 102, resY - 16);
  
  DibujaFractal(screen, fractal, escala, 0, 0, op1, op2, formula);
  //sobrepoblacion(screen,0.75,1);
  
  while(fin == 0)
  {
    SDL_WaitEvent(&evento);
    {
      //Determina el tipo de evento que ocurre y la accion a realizar
      switch (evento.type)
      {
        case SDL_QUIT:
          fin = 1;
          break;
        case SDL_KEYDOWN:
          if (evento.key.keysym.sym == SDLK_ESCAPE) accion = 0;  //Si se presiona ESC se sale de los fractales
          if (evento.key.keysym.sym == SDLK_SPACE) accion = 1;//Si se presiona Espacio se restauran las condiciones iniciales
          if (evento.key.keysym.sym == SDLK_RIGHT) accion = 2;//Si se presiona Flecha Derecha cicla los tipos de fractales.
          if (evento.key.keysym.sym == SDLK_PLUS || evento.key.keysym.sym == SDLK_KP_PLUS) factor *= 0.95;
          if (evento.key.keysym.sym == SDLK_MINUS || evento.key.keysym.sym == SDLK_KP_MINUS) factor /= 0.95;
	  if (evento.key.keysym.sym == SDLK_e) {
	    if (num_iter == 300)
	      num_iter = 3000;
	    else
	      num_iter = 300;
	    DibujaFractal(screen, fractal, escala, despX, despY, op1, op2, formula);
	  }
          break;
        case SDL_MOUSEBUTTONDOWN:
          SDL_GetMouseState(&x, &y);                                     //Obtiene las coordenadas del ratón, y las guarda en x, y
          if(SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1))
          {
            if((x >= resX-102 && x <= resX-85) && (y >= resY-16)) accion = 0;
            else { if((x >= resX-85 && x <= resX-68) && (y >= resY-16)) accion = 2;
              else { if((x >= resX-68 && x <= resX-51) && (y >= resY-16)) accion = 1;
                else { if((x >= resX-51 && x <= resX-34) && (y >= resY-16)) accion = 3;
                  else { if((x >= resX-34 && x <= resX-17) && (y >= resY-16)) accion = 4;
                    else { if((x >= resX-17 && x <= resX) && (y >= resY-16)) accion = 5;
                      else {
                        if(SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1)) accion = 6;    //Acercamiento si se presiona el boton izquierdo del mouse
                      }
                    }
                  }
                }
              }
            }
          }
          if(SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(3)) accion = 7;    //Alejamiento si se presiona el boton derecho del mouse
          if(SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(2)) accion = 8;    //Si se presiona el boton central simplemente se desplaza
          break;
      }
    }
    
    if (accion != -1)
    {
      //Realiza la accion seleccionada
      switch (accion)
      {
        case 0:  //Fin de los fractales
          fin = 1;
          break;
        case 1:  //Condiciones iniciales
          escala = 0.005;
          despX = 0;
          despY = 0;
          a = 0;
          b = 0;
          c = 0.005;
          factor = 0.9;
          DibujaFractal(screen, fractal, escala, despX, despY, op1, op2, formula);
          break;
        case 2:  //Ciclo entre los fractales
          fractal --;
          if (fractal == 0) fractal = 3;
          if(fractal == 2)
          {
            a = despX;
            b = despY;
            op1 = a;
            op2 = b;
            c = escala;
            escala = 0.005;
            despX = 0;
            despY = 0;
          }
          if (fractal == 1)
          {
            despX = a;
            despY = b;
            escala = c;
          }
          if(fractal == 3)
          {
            a = despX;
            b = despY;
          }
          DibujaFractal(screen, fractal, escala, despX, despY, op1, op2, formula);
          break;
        case 3:  //Zoom +
          escala *= factor;
          DibujaFractal(screen, fractal, escala, despX, despY, op1, op2, formula);
          break;
        case 4:  //Zoom -
          escala /= factor;
          DibujaFractal(screen, fractal, escala, despX, despY, op1, op2, formula);
          break;
        case 5:  //Cambio de paleta
          paleta_color ++;
          if (paleta_color == 5) paleta_color = 0;
          DibujaFractal(screen, fractal, escala, despX, despY, op1, op2, formula);
          break;
        case 6:  //Zoom + y desplazamiento
          despX += ((x - resX/2) * escala);
          despY += (-(y - resY/2) * escala);
          escala *= factor;
          DibujaFractal(screen, fractal, escala, despX, despY, op1, op2, formula);
          break;
        case 7:  //Zoom - y desplazamiento
          despX = despX + ((x - resX/2) * escala);
          despY = despY + (-(y - resY/2) * escala);
          escala /= factor;
          DibujaFractal(screen, fractal, escala, despX, despY, op1, op2, formula);
          break;
        case 8:  //Desplazamiento
          despX = despX + ((x - resX/2) * escala);
          despY = despY + (-(y - resY/2) * escala);
          DibujaFractal(screen, fractal, escala, despX, despY, op1, op2, formula);
          break;
      }
      accion = -1;
    }
  }
  SDL_FreeSurface(navegacion);
}


// Mas fractales (sobrepoblaciones, bifurcaciones, pingpong, etc.:
void fractales2(SDL_Surface *screen, int fractal)
{
  int mouseX, mouseY, fin = 0, accion=-1, tipo = 0;
  float x = 0.65, dx = 3.3;
  SDL_Event evento;

  //Se dibuja el fractal deseado:
  if (fractal == 4) collage(screen, tipo+1);
  if (fractal == 5) sobrepoblacion(screen,x,dx);
  if (fractal == 6) automata(tipo);
  
  while(fin == 0)
  {
    SDL_WaitEvent(&evento);
    {
      //Determina el tipo de evento que ocurre y la accion a realizar
      switch (evento.type)
      {
        case SDL_QUIT:
          fin = 1;
          break;
        case SDL_KEYDOWN:                                          //Detecta si se presiona alguna de las siguientes teclas:
          if (evento.key.keysym.sym == SDLK_ESCAPE) accion = 0;    //ESC
          if (evento.key.keysym.sym == SDLK_SPACE) accion = 1;     //Espacio
          if (evento.key.keysym.sym == SDLK_RIGHT) accion = 2;     //Flecha derecha
          if (evento.key.keysym.sym == SDLK_LEFT) accion = 3;      //Flecha Izquierda
          if (evento.key.keysym.sym == SDLK_UP) accion = 4;        //Flecha arriba
          if (evento.key.keysym.sym == SDLK_DOWN) accion = 5;      //Flecha abajo
          if (evento.key.keysym.sym == SDLK_n) accion = 6;         //Tecla n
          break;
      }
    }
    
    if (accion != -1)
    {
      //Realiza la accion seleccionada
      switch (accion)
      {
        case 0:  //ESC
          fin = 1;
          break;
        case 1:  //ESPACIO
          if (fractal == 6) automata(tipo);
          break;
        case 2:  //DERECHA
          if (fractal == 4) {
            tipo ++;
            if (tipo > 2) tipo = 0;
            collage(screen, tipo+1);
          }
          if (fractal == 5 && tipo == 0)  {
            dx += 0.01;
            if (dx > 4) dx = 4;
            sobrepoblacion(screen,x,dx);
          }
          if (fractal == 6) {
            if (tipo == 0) tipo = 1;
            else tipo = 0;
            automata(tipo);
          }
          break;
        case 3:  //IZQUIERDA :-)
          if (fractal == 5 && tipo == 0)  {
            dx -= 0.01;
            if (dx < 1) dx = 1;
            sobrepoblacion(screen,x,dx);
          }
          break;
        case 4:  //ARRIBA
          if (fractal == 5)  {
            x += 0.01;
            if (x > 1) x = 1;
            if (tipo == 0) sobrepoblacion(screen,x,dx);
            else bifurcacion(screen,x);
          }
          break;
        case 5:  //ABAJO
          if (fractal == 5)  {
            x -= 0.01;
            if (x < 0) x = 0;
            if (tipo == 0) sobrepoblacion(screen,x,dx);
            else bifurcacion(screen,x);
          }
          break;
        case 6:  //Tecla n
          if (fractal == 5) {
            if (tipo == 1) {
              tipo = 0;
              sobrepoblacion(screen,x,dx);
            } else {
              tipo = 1;
              bifurcacion(screen, x);
            }
          }
          break;
      }
      accion = -1;
    }
  }
}


void sobrepoblacion(SDL_Surface *screen,float x,float dx)
{
  int t,i,j;
  float x1;
  char cadena[200];
  Uint32 color = SDL_MapRGB(screen->format, 255,109,0), blanco2 = SDL_MapRGB(screen->format, 255,255,255);
  
  Slock(screen);
  for (j=0;j<800;j++)
    for(i=0;i<600;i++){
      if (i < 580) DrawPixel(screen,j,i,0,10,255);
      else DrawPixel(screen, j, i, 255-i, 255-i, 255-i);
    }
  Sulock(screen);

  sprintf(cadena, "Sobrepoblaciones.   Población Inicial: %.2f  Parámetro de crecimiento: %.2f   Presione \"n\" para cambiar a Bifurcaciones.", x, dx);
  fuente=TTF_OpenFont("fuentes/vera.ttf", 12);
  printG(texto, fuente, cadena, negro,'n',10, resY - TTF_FontLineSkip(fuente));

  Draw_Line(screen,50,50,50,550,blanco2);
  Draw_Line(screen,50,550,750,550,blanco2);
  Slock(screen);
  
  for (t=51;t<751;t+=7)
  {
    x1=dx*x*(1-x)*500;
    x=x*500;
    i=t+7;
    Draw_Line(screen,t, 540-x,i,540-x1,color);
    x1=x1/500;
    x=x1;
  }
  Sulock(screen);
  SDL_Flip(screen);
}


void bifurcacion(SDL_Surface *screen,float x)
{
  int t,i,j,R,G,B;
  float x1,dx;
  char cadena[150];
  Uint32 color = SDL_MapRGB(screen->format, 255,109,0), blanco2 = SDL_MapRGB(screen->format, 255,255,255);
  
  Slock(screen);
  for (j=0;j<800;j++)
    for(i=0;i<600;i++){
      if (i < 580) DrawPixel(screen,j,i,0,10,255);
      else DrawPixel(screen, j, i, 255-i, 255-i, 255-i);
    }
  Sulock(screen);

  sprintf(cadena, "Bifurcaciones.   Población Inicial: %.2f                                   Presione \"n\" para cambiar a Sobrepoblaciones.", x);
  fuente=TTF_OpenFont("fuentes/vera.ttf", 12);
  printG(texto, fuente, cadena, negro,'n',10, resY - TTF_FontLineSkip(fuente));
  
  Draw_Line(screen,50,50,50,550,blanco2);
  Draw_Line(screen,50,550,750,550,blanco2);
  
  Slock(screen);
  t=49;
  for (dx=2.6;dx<=4;dx+=0.002) 
  {
    t+=1;
    for (i=1;i<=255;i++)
    {
      R=i;
      G=i;
      B=-i;
      x=dx*x*(1-x)*500;
      DrawPixel(screen,t,540-x,R,G,B);
      x=x/500;
    }
  }
  Sulock(screen);
  SDL_Flip(screen);
}


void automata(int condIni)
{
  int x, y, i, j, k, l, suma, celula, primeraGen[100], segundaGen[100];
  SDL_Color color = {0,0,0,0};

  srand(time(NULL));
  
  Slock(screen);
  for (j = 0; j < 800; j++)
    for(i = 0; i < 600; i++) {
      if (j > 200) DrawPixel(screen,j,i,255,255,255);
      else DrawPixel(screen,j,i, 218, 218, 218);
    }
  Sulock(screen);

  fuente=TTF_OpenFont("fuentes/vera.ttf", 18);
  printG(texto, fuente, "Autómata Celular", color,'b',5, 50);
  fuente=TTF_OpenFont("fuentes/vera.ttf", 12);

  if (condIni == 0) {    //Condiciones iniciales al azar
    for (i = 0; i <= 99; i ++) {
      celula = rand() % 2;
      primeraGen[i] = celula;
    }
    printG(texto, fuente, "Condiciones Iniciales:", color,'b',5, 100);
    printG(texto, fuente, "Primera generación", color,'n',5, 100+TTF_FontLineSkip(fuente));
    printG(texto, fuente, "determinada al azar.", color,'n',5, 100+2*TTF_FontLineSkip(fuente));
  
  } else {             //Condiciones iniciales: una celula viva al centro
    for (i = 0; i <= 99; i ++) {
      if (i == 50) celula = 1;
      else celula = 0;
      primeraGen[i] = celula;
    }
    printG(texto, fuente, "Condiciones Iniciales:", color,'b',5, 100);
    printG(texto, fuente, "Primera generación", color,'n',5, 100+TTF_FontLineSkip(fuente));
    printG(texto, fuente, "consistente en una única", color,'n',5, 100+2*TTF_FontLineSkip(fuente));
    printG(texto, fuente, "célula viva, localizada", color,'n',5, 100+3*TTF_FontLineSkip(fuente));
    printG(texto, fuente, "en el centro.", color,'n',5, 100+4*TTF_FontLineSkip(fuente));
  }

  printG(texto, fuente, "Para cambiar las", color,'b',5, 250);
  printG(texto, fuente, "condiciones iniciales", color,'b',5, 250+TTF_FontLineSkip(fuente));
  printG(texto, fuente, "presione su tecla \"->\".", color,'b',5, 250+2*TTF_FontLineSkip(fuente));
  printG(texto, fuente, "Para regresar presione", color,'b',5, 250+4*TTF_FontLineSkip(fuente));
  printG(texto, fuente, "\"ESC\".", color,'b',5, 250+5*TTF_FontLineSkip(fuente));

  y = 0;
  for (j = 0; j < 100; j ++) {
    x = 200;
    for (i = 0; i <= 99; i ++)
    {
      if (primeraGen[i] == 1) {
        //Dibuja un recuadro de 6x6:
        for (k = x; k < x + 6; k ++)
          for (l = y; l < y + 6; l ++)
            DrawPixel(screen,k,l,0,0,0);
      }
      x += 6;
    }
    y += 6;

    for (i = 1; i <= 98; i ++) {
      suma = primeraGen[i-1] + primeraGen[i] + primeraGen[i+1];
      if (suma == 0) segundaGen[i] = 0;
      if (suma == 1) segundaGen[i] = 1;
      if (suma == 2) segundaGen[i] = 1;
      if (suma == 3) segundaGen[i] = 0;
    }
    segundaGen[0] = segundaGen[98];
    segundaGen[99] = segundaGen[1];
    
    for (i = 0; i <= 99; i ++)
      primeraGen[i] = segundaGen[i];
  }
    
  SDL_Flip(screen);
}


//Dibuja Fractales de Julia y Mandelbrot. Depende del argumento fractal. Es capaz de dibujar el
//fractal a una cierta escala, y enfocado en un punto, utilizando respectivamente los
//argumentos escala, despX, despY. Esto es controlado por la funcion fractales(). DibujaFractal()
//solo dibuja los fractales como le dicen que lo haga.
void DibujaFractal(SDL_Surface *screen, int fractal, double escala, double despX, double despY, double cR, double cI, int formula)
{
  int x, y, iteracion, resXi, resYi, barra;
  double r, i;
  char cadena[1500];
  SDL_Event evento;

  resXi = resX / 2;
  resYi = resY / 2;
  if (fractal == 100)  //Rectifica la escala para el pequeño Julia
  {
    resYi /= 2;
    resXi = resYi;
  }
  if (fractal != 100)
  {
    fuente=TTF_OpenFont("fuentes/vera.ttf", 16);
    printG(texto, fuente, "Calculando ... Espere por favor...", blanco,'b',20, 560);
    SDL_Flip(screen);
    printf("\nPunto seleccionado: (%.15f, %.15f)\nEscala: %.15f\n", despX, despY, escala);
    printf("Calculando fractal... ");
    Slock(screen);
  }

  if (fractal != 100) barra = 16;
  else barra = 0;
  for (x = -resXi; x < resXi; x ++)
  {
    for (y = -resYi; y < (resYi-barra); y ++)
    {
      r = x * escala + despX; //despX y despY definen los desplazamientos en X y Y.
      i = -y * escala + despY;
      switch (fractal)
      {
            case 1:  //Conjunto de Mandelbrot o conjunto de Mandelbrot + Julia
              if (formula == 1) iteracion = mandelbrot_julia(0, 0, r, i);
              if (formula == 2) iteracion = mandelbrot3_julia(0, 0, r, i);
	      if (formula == 3) iteracion = mandelbrot4_julia(0, 0, r, i);
	      if (formula == 4) iteracion = mandelbrot5_julia(0, 0, r, i);
	      if (formula == 5) iteracion = newton(r, i);
              break;
            case 2: case 100: //Conjuntos de Julia (caso 100 es para el pequeño rectangulo)
              if (formula == 1) iteracion = mandelbrot_julia(r, i, cR, cI);
              if (formula == 2) iteracion = mandelbrot3_julia(r, i, cR, cI);
	      if (formula == 3) iteracion = mandelbrot4_julia(r, i, cR, cI);
	      if (formula == 4) iteracion = mandelbrot5_julia(r, i, cR, cI);
	      if (formula == 5) iteracion = newton(r, i);
              break;
            case 3:  //Conjunto de Mandelbrot + Julia
              if (x + resXi > resYi || y + resYi > resYi) {
                if (formula == 1) iteracion = mandelbrot_julia(0, 0, r, i);
                if (formula == 2) iteracion = mandelbrot3_julia(0, 0, r, i);
		if (formula == 3) iteracion = mandelbrot4_julia(0, 0, r, i);
		if (formula == 4) iteracion = mandelbrot5_julia(0, 0, r, i);
		if (formula == 5) iteracion = newton(r, i);
              }

              else iteracion = 0;
              break;
      }

      //Selecciona la paleta de color:
      if (iteracion == num_iter) DrawPixel(screen, x + resXi, y + resYi, 0, 0, 0);
      else {
        switch (paleta_color)
        {
          case 0:    //Paleta Default
            if (iteracion > 0 && iteracion <=8) DrawPixel(screen, x + resXi, y + resYi, 24, 28, 57);
            else { if (iteracion > 8 && iteracion <=9) DrawPixel(screen, x + resXi, y + resYi, 41, 44, 90);
            else { if (iteracion > 9 && iteracion <=10) DrawPixel(screen, x + resXi, y + resYi, 57, 56, 115);
            else { if (iteracion > 10 && iteracion <=11) DrawPixel(screen, x + resXi, y + resYi, 74, 72, 148);
            else { if (iteracion > 11 && iteracion <=12) DrawPixel(screen, x + resXi, y + resYi, 90, 89, 180);
            else { if (iteracion > 12 && iteracion <=13) DrawPixel(screen, x + resXi, y + resYi, 106, 105, 213);
            else { if (iteracion > 13 && iteracion <=15) DrawPixel(screen, x + resXi, y + resYi, 123, 117, 238);
            else { if (iteracion > 15 && iteracion <=17) DrawPixel(screen, x + resXi, y + resYi, 106, 105, 213);
            else { if (iteracion > 17 && iteracion <=18) DrawPixel(screen, x + resXi, y + resYi, 98, 89, 189);
            else { if (iteracion > 18 && iteracion <=20) DrawPixel(screen, x + resXi, y + resYi, 82, 76, 156);
            else { if (iteracion > 20 && iteracion <=22) DrawPixel(screen, x + resXi, y + resYi, 57, 48, 106);
            else { if (iteracion > 22 && iteracion <=23) DrawPixel(screen, x + resXi, y + resYi, 49, 32, 74);
            else { if (iteracion > 23 && iteracion <=25) DrawPixel(screen, x + resXi, y + resYi, 32, 20, 49);
            else { if (iteracion > 25 && iteracion <=27) DrawPixel(screen, x + resXi, y + resYi, 24, 4, 24);
            else { if (iteracion > 27 && iteracion <=28) DrawPixel(screen, x + resXi, y + resYi, 41, 12, 24);
            else { if (iteracion > 28 && iteracion <=30) DrawPixel(screen, x + resXi, y + resYi, 65, 20, 24);
            else { if (iteracion > 30 && iteracion <=35) DrawPixel(screen, x + resXi, y + resYi, 90, 28, 24);
            else { if (iteracion > 35 && iteracion <=40) DrawPixel(screen, x + resXi, y + resYi, 156, 48, 24);
            else { if (iteracion > 40 && iteracion <=45) DrawPixel(screen, x + resXi, y + resYi, 197, 64, 24);
            else { if (iteracion > 45 && iteracion <=50) DrawPixel(screen, x + resXi, y + resYi, 106, 36, 57);
            else { if (iteracion > 50 && iteracion <=55) DrawPixel(screen, x + resXi, y + resYi, 189, 178, 98);
            else { if (iteracion > 55 && iteracion <=60) DrawPixel(screen, x + resXi, y + resYi, 246, 230, 131);
            else { if (iteracion > 60 && iteracion <=65) DrawPixel(screen, x + resXi, y + resYi, 131, 129, 74);
            else { if (iteracion > 65 && iteracion <=70) DrawPixel(screen, x + resXi, y + resYi, 41, 44, 32);
            else { if (iteracion > 70 && iteracion <=75) DrawPixel(screen, x + resXi, y + resYi, 131, 97, 82);
            else { if (iteracion > 75 && iteracion <=80) DrawPixel(screen, x + resXi, y + resYi, 189, 129, 106);
            else { if (iteracion > 80 && iteracion <=85) DrawPixel(screen, x + resXi, y + resYi, 246, 161, 139);
            else { if (iteracion > 85 && iteracion <=90) DrawPixel(screen, x + resXi, y + resYi, 98, 60, 65);
            else { if (iteracion > 90 && iteracion < num_iter) DrawPixel(screen, x + resXi, y + resYi, 106, 85, 189);
            }}}}}}}}}}}}}}}}}}}}}}}}}}}}
            break;
          case 1:  //Paleta Otoño
            DrawPixel(screen, x+resXi, y+resYi, iteracion*iteracion/3.1416, 2*iteracion+3, 1/(iteracion+0.1));
            break;
          case 2:  //Paleta Purpura Profundo
            DrawPixel(screen, x + resXi, y + resYi, iteracion, 1/(iteracion+0.1), iteracion * 1.275);
            break;
          case 3:  //Paleta Atardecer eléctrico
            DrawPixel(screen, x + resXi, y + resYi, iteracion-102, iteracion*3, iteracion * 1.275);
            break;
          case 4:  //Paleta Verduzco
            DrawPixel(screen, x + resXi, y + resYi, iteracion, iteracion*5, iteracion * 1.275);
            break;
        }
      }
    }
  }

  if (fractal == 3)  //Conjunto de Mandelbrot + Julia. DibujaFractal se utiliza recursivamente para dibujar el pequeño recuadro.
  {
    DibujaFractal(screen, 100, 2.5/resYi, 0, 0, despX, despY, formula);      //Dibuja pequeña Julia
    for(x = 0; x <= resYi; x ++) DrawPixel(screen, x, resYi, 255, 255, 255);   //Dibuja recuadro contenedor
    for(y = 0; y < resYi; y ++) DrawPixel(screen, resYi, y, 255, 255, 255);
  }
  if(fractal != 100)
  {
    for (x = 0; x < resX-102; x ++)    //Colorea la parte inferior de la pantalla
      for (y = resY - 16; y < resY; y ++)
        DrawPixel(screen, x, y, 255-y*2, 255-y*2, 255-y*2);
  }
  Sulock(screen);
  
  if((fractal == 1 || fractal == 3) && formula == 1) sprintf(cadena, "Mandelbrot: Punto seleccionado: (%.15f, %.15f)  Escala: %.15f", despX, despY, escala);
  if((fractal == 1 || fractal == 3) && formula == 2) sprintf(cadena, "Mandelbrot^3: Punto seleccionado: (%.15f, %.15f)  Escala: %.15f", despX, despY, escala);
  if((fractal == 1 || fractal == 3) && formula == 3) sprintf(cadena, "Mandelbrot^4: Punto seleccionado: (%.15f, %.15f)  Escala: %.15f", despX, despY, escala);
  if((fractal == 1 || fractal == 3) && formula == 4) sprintf(cadena, "Mandelbrot^5: Punto seleccionado: (%.15f, %.15f)  Escala: %.15f", despX, despY, escala);
  if(formula == 5) sprintf(cadena, "Newton: Punto seleccionado: (%.15f, %.15f)  Escala: %.15f", despX, despY, escala);
  if(fractal == 2 && formula != 5) sprintf(cadena, "Julia c=(%.5f, %.5f): Punto seleccionado: (%.5f, %.5f)  Escala: %.15f", cR, cI, despX, despY, escala);
  fuente=TTF_OpenFont("fuentes/vera.ttf", 12);
  if(fractal != 100) printG(texto, fuente, cadena, blanco,'n',10, resY - TTF_FontLineSkip(fuente));
  SDL_Flip(screen);
  printf("HECHO\n");
}


//mandelbrot_julia() prueban si un punto tiende al infinito a hacia algun atractor:
int mandelbrot_julia (double r, double i, double cR, double cI)
{
  int iteracion;
  double distancia, rn;
  iteracion = 0;
  distancia = 0;
  while (iteracion < num_iter && distancia < 4)
  {
    rn = r * r - i * i + cR;
    i = 2 * r * i + cI;
    r = rn;
    distancia = r * r + i * i;
    iteracion ++;
  }
  return iteracion;
}

int mandelbrot3_julia (double r, double i, double cR, double cI)
{
  int iteracion;
  double distancia, rn;
  iteracion = 0;
  distancia = 0;
  while (iteracion < num_iter && distancia < 4)
  {
    rn = r*r*r - 3*r*i*i + cR;
    i = 3*r*r*i - i*i*i + cI;
    r = rn;
    distancia = r * r + i * i;
    iteracion ++;
  }
  return iteracion;
}

int mandelbrot4_julia (double r, double i, double cR, double cI)
{
  int iteracion;
  double distancia, rn, rr, ii;
  iteracion = 0;
  distancia = 0;
  while (iteracion < num_iter && distancia < 4)
  {
    rr = r*r;
    ii = i*i;
    rn = rr*rr+ii*ii-6*rr*ii + cR;
    i = 4*(rr*r*i-r*ii*i) + cI;
    r = rn;
    distancia = r * r + i * i;
    iteracion ++;
  }
  return iteracion;
}

int mandelbrot5_julia (double r, double i, double cR, double cI)
{
  int iteracion;
  double distancia, rn, rr, ii;
  iteracion = 0;
  distancia = 0;
  while (iteracion < num_iter && distancia < 4)
  {
    rr = r*r;
    ii = i*i;
    rn = rr*rr*r+5*r*ii*ii-10*rr*r*ii + cR;
    i = 5*rr*rr*i-10*rr*ii*i+ii*ii*i + cI;
    r = rn;
    distancia = r * r + i * i;
    iteracion ++;
  }
  return iteracion;
}

int newton (double r, double i)
{
  int iteracion;
  double rn, x, ii, rr, distancia=0;
  iteracion = 0;
  while ( !(distancia> 0.9999999 && distancia < 1.0000001) && iteracion < num_iter)
  {
    rr = r*r;
    ii = i*i;
    x = 3.0*((rr - ii)*(rr - ii) + 4.0*rr*ii);
    if (x==0) x = 0.0000000001;
    rn = (2.0/3.0)*r + (rr - ii)/x;
    i = (2.0/3.0)*i - 2.0*r*i/x;
    r = rn;
    distancia = r * r + i * i;
    iteracion ++;
  }
  
  return iteracion;
}


//Dibuja los fractales de Triangulo de Sierpinski, helecho, y arbusto:
void collage(SDL_Surface *screen,int tipo)
{
  int n,x2,y2,m,l=1;
  float r,s,h,k,A,B;
  float p1,p2,p3,p4;
  float d,x,y,x1,y1; 
  double f;
  x=0;
  y=0;
  f=3.1416/180;
  srand(time(NULL));
  Slock(screen);
  for (x = 0; x < resX; x ++)
    for (y = 0; y < resY; y ++)
      DrawPixel(screen, x, y, 0, 0, 0); //if (y>300) DrawPixel(screen, x, y, 65, y/3, 49);
      //else DrawPixel(screen, x, y, 180+x/10, 218+y/10, 255);

  switch(tipo)
  {
    case 1: // Triagulo de Sierpinski
      for (n=1;n<=200000;n++)
      {
        d= 1+rand()%3;
        if (d==1) {
          r=0.5; s=0.5; h=0; k=0; A=0; B=0;
          m = 100;
        }
        if (d==2) {
          r=0.5; s=0.5; h=0.5; k=0; A=0; B=0;
          m = 150;
        }
        if (d==3) {
          r=0.5; s=0.5; h=0.25; k=0.5; A=0; B=0;
          m = 200;
        }

        x=r*cos(A*f)*x-s*sin(B*f)*y+h;    //Transformaciones de rotacion, traslacion y escala
        y=r*sin(A*f)*x+s*cos(B*f)*y+k;
        x2=(x*500)+150;
        y2=540-(y*500);
        if(x2<800 && x2>0 && y2 > 0 && y2 < 600) DrawPixel(screen,x2,y2,5*m,x2/4,y2/3);
      }
      SDL_Flip(screen);
      break;

    case 2: // Helecho
      p1=0.005; p2=0.0975; p3=0.0975; p4 = 0.8;
      for (n=1;n<=200000;n++)
      {
        d= 1+rand()%8000;
        d= d*0.0001;
        
        if (d<=p1) {
          r=0; s=0.16; h=0; k=0; A=0; B=0;
          m = 100;
        }
        if (d>p1 && d<=p1+p2) {
          r=0.3; s=0.37; h=0; k=0.44; A=135; B=-40;
          m = 150;
        }
        if(d>p1+p2 && d<=p1+p2+p3) {
          r=0.3; s=0.34; h=0; k=1.6; A=45; B=45;
          m = 200;
        }
        if(d>p1+p2+p3 && d<p1+p2+p3+p4) {
          r=0.85; s=0.85; h=0; k=1.6; A=-1.5; B=-1.5;
          m = 255;
        }

        x=r*cos(A*f)*x-s*sin(B*f)*y+h;    //Transformaciones de rotacion, traslacion y escala
        y=r*sin(A*f)*x+s*cos(B*f)*y+k;
        x2=(x*50)+400;
        y2=550-(y*50);
        if(x2<800 && x2>0 && y2 > 0 && y2 < 600) DrawPixel(screen,x2,y2,x2/2,m,l/2);
        l = m;
      }
      SDL_Flip(screen);
      break;

    case 3: //Arbusto
  
    p1=0.05; p2=0.3; p3=0.3;
  
    for (n=1;n<=200000;n++)
    {
      d= 1+(rand()%100);
      d= d*0.01;
      
      if (d<=p1)
      {
        r=0.47; s=0.12; h=0; k=0.77; A=80; B=-50;
        m=100;
      }
      if (d>p1 && d<=p1+p2)
      {
        r=0.49; s=0.66; h=0.42; k=0.75; A=60.5; B=47.8;
        m=150;
      }
      if(d>p1+p2 && d<=p1+p2+p3)
      {
        r=0.53; s=0.55; h=0.9; k=1.3; A=-20.6; B=-48.9;
        m=200;
      }
      if (d>p1+p2+p3)
      {
        r=0.53; s=0.76; h=0.6; k=0.1; A=-10; B=-2;
        m=255;
      }
      
      x=r*cos(A*f)*x-s*sin(B*f)*y+h;    //Transformaciones de rotacion, traslacion y escala
      y=r*sin(A*f)*x+s*cos(B*f)*y+k;

      x2=80+(x*250);
      y2=500-(y*250);
      if(x2<800 && x2>0 && y2 > 0 && y2 < 600) DrawPixel(screen,x2,y2,l,m,100);
      l = m-50;
    }
    SDL_Flip(screen);
    break;
  }
  Sulock(screen);
}


//Coloca una Imagen en la pantalla
void DibujaIMG(SDL_Surface *img, int x, int y)
{
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  SDL_BlitSurface(img, NULL, screen, &dest);
}


//Redibuja una porcion de una imagen
void ActIMG(SDL_Surface *img, int x, int y, int w, int h, int x2, int y2)
{
  SDL_Rect dest;
  SDL_Rect dest2;
  dest.x = x;
  dest.y = y;
  dest2.x = x2;
  dest2.y = y2;
  dest2.w = w;
  dest2.h = h;
  SDL_BlitSurface(img, &dest2, screen, &dest);
}


//Imprime una cadena de texto grafica.
void printG(SDL_Surface *superficie, TTF_Font *tipoFuente, const char *frase, SDL_Color color, int tipo, int x, int y)
{
  switch (tipo)
  {
    case 'b':
      TTF_SetFontStyle(tipoFuente, TTF_STYLE_BOLD);
      break;
    case 'c':
      TTF_SetFontStyle(tipoFuente, TTF_STYLE_ITALIC);
      break;
    case 'n':
      TTF_SetFontStyle(tipoFuente, TTF_STYLE_NORMAL);
      break;
  }
  superficie = TTF_RenderUTF8_Blended(tipoFuente, frase, color);
  if (x == -1) x = resX/2-superficie->w/2;    //Si se selecciona -1 para x, se centra el texto en la pantalla
  if (y == -1) y = resY/2-superficie->h/2;    //Si se selecciona -1 para y, se centra el texto en la pantalla
  DibujaIMG(superficie, x, y);
}


//Función encargada de dibujar un pixel en la pantalla.
//NOTA: la funcion DrawPixel se tomo de la introduccion a la libreria SDL en:
//<http://www.libsdl.org/intro/usingvideo.html>
void DrawPixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B)
{
  Uint32 color = SDL_MapRGB(screen->format, R, G, B);
  switch (screen->format->BytesPerPixel)
  {
    case 1: // Assuming 8-bpp
      {
        Uint8 *bufp;
        bufp = (Uint8 *)screen->pixels + y*screen->pitch + x;
        *bufp = color;
      }
      break;
    case 2: // Probably 15-bpp or 16-bpp
      {
        Uint16 *bufp;
        bufp = (Uint16 *)screen->pixels + y*screen->pitch/2 + x;
        *bufp = color;
      }
      break;
    case 3: // Slow 24-bpp mode, usually not used
      {
        Uint8 *bufp;
        bufp = (Uint8 *)screen->pixels + y*screen->pitch + x * 3;
        if(SDL_BYTEORDER == SDL_LIL_ENDIAN)
        {
          bufp[0] = color;
          bufp[1] = color >> 8;
          bufp[2] = color >> 16;
        } else {
          bufp[2] = color;
          bufp[1] = color >> 8;
          bufp[0] = color >> 16;
        }
      }
      break;
    case 4: // Probably 32-bpp
      {
        Uint32 *bufp;
        bufp = (Uint32 *)screen->pixels + y*screen->pitch/4 + x;
        *bufp = color;
      }
      break;
  }
}

//Terminacion de las librerias SDL, cierre de las fuentes, y destruccion de algunas capas.
void salida()
{
  SDL_FreeSurface(texto);
  SDL_FreeSurface(fondo);
  SDL_FreeSurface(screen);
  TTF_CloseFont(fuente);
  fuente=NULL;
  TTF_Quit();
  SDL_Quit();
}


//Inicializa el sistema SDL
void inicializacion()
{
  if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
  {
    printf("ERROR %d: No se pudo inicializar el sistema SDL.\n", SDL_GetError());
    exit(1);
  }
  atexit(salida);
  
  if(TTF_Init()==-1) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
  }

  //Si se desea modo de pantalla completa:
  //screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_FULLSCREEN);
  //en lugar de:
  screen=SDL_SetVideoMode(resX,resY,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  if ( screen == NULL )
  {
    printf("ERROR %s: Imposible definir resolución a %dx%d.\n", SDL_GetError(), resX, resY);
    exit(1);
  }

  //Establece el icono y el titulo de la ventana:
  SDL_WM_SetCaption("El Aleph y sus Espejos 1.1", "Aleph");
  SDL_WM_SetIcon(IMG_Load("imagenes/aleph.png"),NULL);
}


//Funciones encargadas de Bolquear y desbloquear la pantalla: Slock y Sulock
void Slock(SDL_Surface *screen)
{
  if ( SDL_MUSTLOCK(screen) )
  {
    if ( SDL_LockSurface(screen) < 0 )
    {
      return;
    }
  }
}
void Sulock(SDL_Surface *screen)
{
  if ( SDL_MUSTLOCK(screen) )
  {
    SDL_UnlockSurface(screen);
  }
}
