/*
 *   This file is part of the MLV Library.
 *
 *   Copyright (C) 2012 Adrien Boussicault, Marc Zipstein
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
 * \file MLV_device_with_buttons.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit des énumérations et des prototypes de fonctions pour 
 *        manipuler des boutons de différents matériels (bouttons de souris, 
 *        boutons de claviers, etc ...)
 *
 */

#ifndef __MLV__MLV_DEVICE_WITH_BUTTONS_H__
#define __MLV__MLV_DEVICE_WITH_BUTTONS_H__

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Énumère les différents états possibles d'un bouton.
 */
typedef enum {
	MLV_PRESSED, /**< \~french Le bouton est en position appuyée */
	MLV_RELEASED /**< \~french Le bouton est en position relachée */
} MLV_Button_state;


#ifdef __cplusplus
}
#endif

#endif
