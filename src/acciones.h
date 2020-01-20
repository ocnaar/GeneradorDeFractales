/***************************************************************************
 *   acciones.h                                                            *
 *   Prototipos de las funciones utilizadas en acciones.c                  *
 ***************************************************************************
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

void entradas_principal(int, int, int, SDL_Surface *);
void icon_menu_princ(SDL_Surface *, int, int);
void entradas_fractal(int, int, int, SDL_Surface *);
void icon_fractal(SDL_Surface *, int, int);
void entradas_fractal_adicional(int, int, int, SDL_Surface *);
void icon_fractal_adicional(SDL_Surface *, int, int);
void icon_marcoT(SDL_Surface *, int, int);
int entradas_opciones();
void icon_opciones(int);
void escribe_titulo(int);
int inserta_texto(int, int, SDL_Surface *);
