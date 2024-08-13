/*
 *   This file is part of the MLV Library.
 *
 *   Copyright (C) 2010,2011,2012 Adrien Boussicault, Marc Zipstein
 *
 *
 *    This Library is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This Library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this Library.  If not, see <http://www.gnu.org/licenses/>.
 */

/** \~french 
 * \file MLV_mouse.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 * 
 * \brief Ce fichier définit les prototypes des fonctions qui permettent 
 *        d'utiliser la souris.
 *
 */

#ifndef __MLV__MLV_MOUSE_H__
#define __MLV__MLV_MOUSE_H__

#ifndef MEMORY_DEBUG
#include <SDL/SDL.h>
#else
#include "memory_debug.h"
#endif

#include "MLV_device_with_buttons.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Énumère les différents bouttons de la souris
 *
 */
typedef enum{
	MLV_BUTTON_LEFT = SDL_BUTTON_LEFT, /**< \~french  Bouton gauche de la souris */
	MLV_BUTTON_MIDDLE = SDL_BUTTON_MIDDLE, /**< \~french  Bouton du milieu de la souris */
	MLV_BUTTON_RIGHT = SDL_BUTTON_RIGHT /**< \~french  Bouton droit de la souris */
} MLV_Mouse_button;

/** \~french 
 *
 * \brief Suspend l'exécution jusqu'à ce que l'utilisateur clique sur le bouton
 *        gauche de la souris.
 *
 * Au moment où l'utilisateur clique, la fonction retourne les
 * coordonnées de la position de la souris dans la fenêtre.
 *
 * \param x Coordonnée en X de la position de la souris dans la fenêtre.
 * \param y Coordonnée en Y de la position de la souris dans la fenêtre.
 */
void MLV_wait_mouse(int *x, int *y);

/** \~french 
 *
 * \brief Suspend l'exécution jusqu'à ce que l'utilisateur clique sur le bouton
 *        gauche de la souris où jusqu'à ce qu'un nombre de secondes, passé en 
 *        paramètres, se soient écoulées.
 *
 * Au moment où l'utilisateur clique, la fonction retourne les
 * coordonnées de la position de la souris dans la fenêtre.
 *
 * \param x Coordonnée en X de la position de la souris dans la fenêtre.
 * \param y Coordonnée en Y de la position de la souris dans la fenêtre.
 * \param seconds Le nombre de second à attendre avant de quitter la fonction.
 * \return Renvoie 1 si l'utilisateur a cliqué avec le bouton gauche de la souris,
 *         et 0 si le temps s'est écoulé.
 */
int MLV_wait_mouse_or_seconds(int *x, int *y, int seconds);

/** \~french
 * \brief Convertit le code associé à un boutton de la souris (MLV_Mouse_button) en 
 *        chaîne de caratères.
 *
 * \param button_code Le code du bouton.
 * \return La chaîne de caratères correspondant au code du boutton de la
 *          souris passé en paramètre.
 */
const char* MLV_convert_mouse_button_to_string( MLV_Mouse_button button_code );

/** \~french
 * \brief Convertit une chaîne de caractères en un code bouton.
 *
 * \param button_string La chaîne de caractères à convertir.
 * \return Le code bouton associé à la chaîne de caractères.
 */
MLV_Mouse_button MLV_convert_string_to_mouse_button( const char* button_string );

/** \~french
 *
 * \brief Renvoie la position courante de la souris. 
 *
 * \param x Coordonnée en X de la position de la souris dans la fenêtre.
 * \param y Coordonnée en Y de la position de la souris dans la fenêtre.
 */
void MLV_get_mouse_position( int* x, int* y );

/** \~french
 *
 * \brief Renvoie l'état (préssé ou relaché) d'un bouton de la souris.
 *
 * \param mouse_button Le code du bouton de la souris
 * \return L'état du bouton. 
 */
MLV_Button_state MLV_get_mouse_button_state( MLV_Mouse_button mouse_button );

#ifdef __cplusplus
}
#endif

#endif
